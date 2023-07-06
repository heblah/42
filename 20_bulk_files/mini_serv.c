
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

typedef struct s_data
{
	char	buf[4096];
	char	msg[4096];
	int		srvsd;
	struct s_client
	{
		int	id;
		int	sd;
		struct s_client *next;
	}	*client;
}	t_data;

void	fatal_err( t_data *data )
{
	struct s_client	*tmp = data->client, *tmp2;
	char *err;

	err = "Fatal error\n";
	write( 2, err, strlen( err ) );
	if ( tmp != NULL )
	{
		while ( tmp )
		{
			tmp2 = tmp;
			tmp = tmp->next;
			close( tmp2->sd );
			free( tmp2 );
		}
	}
	close( data->srvsd );
	exit( 1 );
	return;
}

int	get_maxsd( t_data *data )
{
	struct s_client	*tmp = data->client;
	int				maxsd = data->srvsd;

	while ( tmp )
	{
		if ( tmp->sd >= maxsd )
			maxsd = tmp->sd;
		tmp = tmp->next;
	}
	return maxsd;
}

void	add_client( t_data *data, int newsd )
{
	struct s_client *new = NULL;
	struct s_client	*tmp = data->client;
	int				id = 0;

	new = malloc( 1 * sizeof( struct s_client ) );
	if ( new == NULL )
		fatal_err( data );
	new->next = NULL;
	new->sd = newsd;
	if ( data->client == NULL )
	{
		data->client = new;
		new->id = id;
	}
	else
	{
		while ( tmp && tmp->next )
		{
			tmp = tmp->next;
			id = tmp->id;
		}
		tmp->next = new;
		new->id = id + 1;
	}
}

void	rm_client( t_data *data, int sd )
{
	struct s_client *tmp = data->client;
	struct s_client *del = NULL;

	if ( tmp != NULL )
	{
		while ( tmp && tmp->next )
		{
			del = tmp->next;
			if ( del->sd == sd )
			{
				tmp->next = tmp->next->next;
				close( del->sd );
				free( del );
			}
			tmp = tmp->next;
		}
	}
}

int	get_id( t_data *data, int sd )
{
	struct s_client	*tmp = data->client;
	
	while ( tmp )
	{
		if ( tmp->sd == sd )
			return tmp->id;
		tmp = tmp->next;
	}
	return -1;
}

void	send_msg( t_data *data, char* msg, int sd )
{
	struct s_client *tmp = data->client;

	while( tmp )
	{
		if ( tmp->sd != sd )
		{
			if ( send( tmp->sd, msg, strlen( msg ), 0 ) == -1 )
				fatal_err( data );
		}
		tmp = tmp->next;
	}
	bzero( data->msg, strlen( data->msg ));
	bzero( data->buf, strlen( data->buf ));
}

int	main( int argc, char **argv )
{
	t_data	data;
	int	srvsd, rc, newsd;
	int	opt = 1;
	fd_set master_set, read_set, write_set;//, working_set;
	struct sockaddr_in	addrin;
	struct sockaddr		*addr = ( struct sockaddr * )&addrin;

	if ( argc != 2 )
	{
		write( 2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n") );
		return 1;
	}

	bzero( data.msg, sizeof( data.msg ) );
	bzero( data.buf, sizeof( data.buf ) );
	addrin.sin_family = AF_INET;
	addrin.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrin.sin_port = htons( atoi(argv[1]) );
	srvsd = socket( AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0 );
	if ( srvsd == -1)
		fatal_err( &data );
	if ( setsockopt( srvsd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof( opt ) ) == -1 )
		fatal_err( &data );
	if ( bind( srvsd, addr, sizeof(*addr) ) == -1 )
		fatal_err( &data );
	if ( listen( srvsd, 0 ) == -1 )
		fatal_err( &data );

	FD_ZERO( &master_set );
	FD_SET( srvsd, &master_set ); 
	printf("is listening on port %i\n", atoi(argv[1]));

	data.srvsd = srvsd;
	data.client = NULL;
	while ( 1 )
	{
		read_set = master_set;
		write_set = master_set;
		rc = select( get_maxsd( &data )  + 1, &read_set, &write_set, NULL, NULL );
		if ( rc < 0 )
			fatal_err( &data );
		for( int i = data.srvsd; i <= get_maxsd( &data ); i++ )
		{
			if ( FD_ISSET( i, &read_set ) && i == data.srvsd )
			{
				newsd = accept( data.srvsd, 0, 0 );
				if ( newsd == -1 )
					fatal_err( &data );
				add_client( &data, newsd );
				FD_SET( newsd, &master_set );
				FD_CLR(data.srvsd, &read_set);
				send( newsd, "you're in chat\n", strlen( "you're in chat\n" ), 0 );
				sprintf( data.msg, "server: client %d just arrived\n", get_id( &data, newsd ) );
				send_msg( &data, data.msg, newsd );
				break;
			}
			else if ( FD_ISSET( i, &read_set ) )
			{
				if ( recv( i, data.buf, 1, MSG_PEEK ) == 0 )
				{
					sprintf( data.msg, "server: client %d just left\n", get_id( &data, i ) );
					send_msg( &data, data.msg, i );
					FD_CLR( i, &master_set );
					rm_client( &data, i );
				}
				else
				{
					rc = recv( i, data.buf, sizeof( data.buf ), 0 );
					if ( rc == -1 )
						fatal_err( &data );
					sprintf( data.msg, "client %d: %s", get_id( &data, i ), data.buf );
					send_msg( &data, data.msg, i );
				}
			}
		}
	}
	return 0;
}
