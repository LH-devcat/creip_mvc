<?php

class controleur_generateurcode {
	
	function afficherForm () {
		
		
			include MOD_BASEPATH."/vue/vue_generateurcode.php";
			$vue = new vue_generateurcode();
			$vue -> form_Generer_Code ();
		
	}
	
	function generationcode (){
		
		include MOD_BASEPATH."/modele/modele_generateurcode.php";
		$modele = new modele_generateurcode();
		$modele::codeGenerer();
		
	}
	
	
	
	
	
}

?>