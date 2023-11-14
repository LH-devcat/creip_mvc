<?php
if (! defined ('TEST_INCLUDE'))
   die ("Vous ne pouvez pas accéder directement à ce fichier");
/*if ( defined ('$_SESSION["id_user"]'))
   die ("Vous possédez deja un compte");*/
	

	define("MOD_BASEPATH","modules/mod_connexion");
	include MOD_BASEPATH."/controleur/controleur_connexion.php";
	
	if (empty($_GET['action'])){
	$action = "affichForm";
	}else{
	$action = $_GET['action'];
	}

	switch ($action){
	case"affichForm":
		$controleur=new controleur_connexion();
		$controleur->affichageFormCo();
	break;
	case"verifUser":
		$controleur=new controleur_connexion();
		$controleur->verifUser();
	break;
	case"affichageMdpOublier":
		$controleur=new controleur_connexion();
		$controleur->affichageMdpOublier();
	break;
	case"mdpoublier":
		$controleur=new controleur_connexion();
		$controleur->mdpOublier();
	default:
	echo "default !";
	}

?>
