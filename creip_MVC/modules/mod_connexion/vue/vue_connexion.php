<?php

	class vue_connexion{

		static function affichageFormCo(){
?>
		<!DOCTYPE html>
		<html>
			<head>
				<title>Connexion</title>
				<meta charset="utf-8" />
				<link rel="stylesheet" href="css/style.css" media="screen" type="text/css" />
			</head>
			<body>
				<div class="login-card">
					<h1>Connexion</h1></br>
					<form action="index.php?module=connexion&action=verifUser" method="post">
					<input type="text" name="login" placeholder="identifiant" required/>
					<input type="password" name="password" placeholder="mot de passe" required/>
					<input type="submit" class="login login-submit" value="Se connecter"/>
					<a href="index.php?module=connexion&action=affichageMdpOublier">Mot de passe oublié ?</a> 
					</form>
				</div>
			</body>
		</html>
<?php
		}
		
		static function affichageMdpOublier (){
			
?>
		<!DOCTYPE html>
		<html>
			<head>
				<title>Connexion</title>
				<meta charset="utf-8" />
				<link rel="stylesheet" href="css/style.css" media="screen" type="text/css" />
			</head>
			<body>
				<div class="login-card">
				<h1>Récupération de mot de passe</h1></br>
				<form action="index.php?module=connexion&action=mdpoublier" method="post">
				Login<input type="text" name="login"/>
				E-mail<input type="password" name="mail"/>
				<input type="submit" class="login login-submit" value="Envoyer"/>		
				</form>
				</div>
			</body>
		</html>
<?php
			
		}
	
		

	
	}


?>