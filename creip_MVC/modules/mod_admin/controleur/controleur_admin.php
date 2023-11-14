<?php

class controleur_admin {
	
	function affichage (){
		include MOD_BASEPATH."/vue/vue_admin.php";
		$vue = new vue_admin();
		$vue->affichage_admin ();
		
	}
	
	
	
}






?>