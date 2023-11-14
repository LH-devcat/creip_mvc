<?php
if (! defined ('TEST_INCLUDE'))
   die ("Vous ne pouvez pas accéder directement à ce fichier");


	define("MOD_BASEPATH","modules/mod_activercode");
	include MOD_BASEPATH."/controleur/controleur_activercode.php";

	if (empty($_GET['activercode'])){
	$activercode = "affichAccueil";
	}/*else{
	$accueil = $_GET['accueil'];
	}*/
	
	switch ($activercode){
		case "affichAccueil":
			$controleur=new controleur_activercode();
			$controleur->affichVue_activercode();
		break;
	
		default:
			echo "default !";
	}

?>
