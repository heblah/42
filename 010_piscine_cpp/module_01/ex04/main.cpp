/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:32:23 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/13 11:29:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	file2string(std::ifstream &ifs)
{
	std::string	str;
	std::string	buffer;

	while (ifs.eof() == false)
	{
		std::getline(ifs, buffer);
		str += buffer;
		if (ifs.eof() == false)
			str += "\n";
	}
	return (str);
}

std::string	replace(std::string str, std::string oldsub, std::string newsub)
{
	std::string	newstr;
	size_t		pos = 0;
	size_t		oldlen = oldsub.size();

	while (str.find(oldsub, pos) != std::string::npos)
	{
		newstr += str.substr(pos, str.find(oldsub, pos) - pos);
		newstr += newsub;
		pos = str.find(oldsub, pos) + oldlen;
	}
	newstr += str.substr(pos, str.size());
	return (newstr);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buffer;

	if (argc == 4)
	{
		ifs.open(argv[1]);
		ofs.open("new_file");
	}
	if (argc == 4 && ifs.good() == true)
	{
		buffer = file2string(ifs);
		buffer = replace(buffer, argv[2], argv[3]);
		if (ofs.good() == true)
		{
			ofs << buffer;
			if (ofs.bad() == true)
			{
				std::cout << "Error: something wrong appened when writing in the new file." << std::endl;
				return (1);
			}
		}
	}
	else if (argc == 4 && ifs.good() == false)
	{
		std::cout << "Error: wrong input file." << std::endl;
		return (1);
	}
	else if (argc != 4 && ifs.good() == true)
	{
		std::cout << "Error: wrong arguments. The correct form is:";
		std::cout << "./replace filename oldstr newstr" << std::endl;
		return (1);
	}
	return (0);
}
