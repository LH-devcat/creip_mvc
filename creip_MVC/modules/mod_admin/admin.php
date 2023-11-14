<?php

if (! defined ('TEST_INCLUDE'))
   die ("Vous ne pouvez pas accéder directement à ce fichier");


	define("MOD_BASEPATH","modules/mod_admin");
	include MOD_BASEPATH."/controleur/controleur_admin.php";

	if (empty($_GET['admin'])){
	$admin = "affichAccueil";

	
	switch ($admin){
		case "affichAccueil":
			$controleur=new controleur_admin();
			$controleur->affichage();
		break;
	
		default:
			echo "default !";
	}
	}





?>