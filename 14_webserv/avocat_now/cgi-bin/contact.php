#!/usr/bin/env php

<?php

parse_str(file_get_contents('php://stdin'), $_POST);
$username = $_POST["username"];
$email = $_POST["email"];
$message = $_POST["message"];

echo("Content-Type: text/html\r\n\r\n");

echo "<html lang=\"fr\">

<head>
    <meta charset=\"UTF-8\">
    <link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi\" crossorigin=\"anonymous\">
    <link rel=\"stylesheet\" href=\"../cgi-bin/css/style.css\">
    <title>Contact</title>
</head>

<body>
	<div class=\"formulaire\">
		<h1>Message Envoyé</h1>
		<div class=\"data\">
			<p>
				Merci pour votre message, $username.
			</p>
			<p>
				Votre message :
			</p>
			<p>
				De $email :
			</p>
			<p>
				$message
			</p>
		</div>
		<a href=\"../../../index.html\"><button id=\"connexion\">Index</button></a>
	</div>
</body>

</html>";
?>