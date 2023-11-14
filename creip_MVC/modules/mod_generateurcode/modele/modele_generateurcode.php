<?php

class modele_generateurcode {
	
	
	static function generer_code (){
		
		$code = "";
       
    $chaine = "abcdefghjkmnopqrstuvwxyzABCDEFGHJKLMNOPQRSTUVWXYZ0123456789";
    $longeur_chaine = strlen($chaine);
        for($i = 1; $i <= 10; $i++)
        {
            $place_aleatoire = mt_rand(0,($longeur_chaine-1));
            $code .= $chaine[$place_aleatoire];
        }
    return $code;   
		
	}
	
	static function ajouter_code ($code,$rank){
		
		require('dns.php');
		$connexion = new PDO ($dns, $user, $password);
	$req = $connexion->prepare("INSERT INTO connexion (activationCode, rank, actif) VALUES (?, ?, 0)");
	$req->execute(array($code, $rank));
		
		
	}
	
	static function codeGenerer (){
		
		if (isset($_POST['nbrCodes']))
		{
			for($i=0; $i<$_POST['nbrCodes']; $i++)
			{
				$modele = new modele_generateurcode();
				$codeActivation = $modele::generer_code();
				$modele::ajouter_code($codeActivation, $_POST['Type']);
				//echo $codeActivation."</br>";
			}
		}
	}
	
}

?>