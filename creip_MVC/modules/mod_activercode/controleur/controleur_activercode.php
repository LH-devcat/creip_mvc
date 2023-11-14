<?php

	class controleur_activercode {
		
		function affichVue_activercode(){
			include MOD_BASEPATH."/modele/modele_activercode.php";
			include MOD_BASEPATH."/vue/vue_activercode.php";
			$modele=modele_activercode::activationCode();
			vue_activercode::affichVue_activercode($modele);
		}
		
		
	}
	
?>