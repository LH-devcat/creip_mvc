<?php

if (! defined ('TEST_INCLUDE'))
   die ("Vous ne pouvez pas accéder directement à ce fichier");

	

	define("MOD_BASEPATH","modules/mod_generateurcode");
	include MOD_BASEPATH."/controleur/controleur_generateurcode.php";
	
	if (empty($_GET['action'])){
	$action = "affichForm";
	}else{
	$action = $_GET['action'];
	}

	switch ($action){
	case"affichForm":
		$controleur=new controleur_generateurcode();
		$controleur->afficherForm ();
	break;
	case"generercode":
		$controleur=new controleur_generateurcode();
		$controleur->afficherForm ();
		$controleur->generationcode();
	break;
	
	echo "default !";
	}





?>