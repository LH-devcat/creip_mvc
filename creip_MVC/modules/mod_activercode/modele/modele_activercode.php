<?php

	 class modele_activercode {
			
			static function IDCode($code)
			{
				require('dns.php');
				$connexion = new PDO ($dns, $user, $password);
				$req = $connexion->prepare("SELECT id,actif,rank FROM connexion where activationCode='".$code."'");
				$req->execute();
				$res = $req->fetch(PDO::FETCH_ASSOC);
				if($res)
				{
					if($res['actif']==1)
					{
					//return true;
						return 'actif';
					}else{
				return $res;
					}//return $res['id'];
				}else return false;
			}
			
			static function activationCode ()
			{
				
				if (isset($_POST['code']))
					{
						$IDcompte = modele_activercode::IDCode($_POST['code']);
						if($IDcompte==false)
						{
							echo "<p style='color:red; font-size:150%;' class='text-center wow fadeInDown'>Le code entré est invalide</p>";
						}else{
							if($IDcompte=='actif')
							{
								echo "<p style='color:red; font-size:150%;' class='text-center wow fadeInDown'>Le code entré a déjà été activé</p>";
							}else{
								$_SESSION['activationID']= $IDcompte['id'];
								if($IDcompte['rank']==0)
								{
									header('Location: etudiant/creercompteEtudiant.php');
								}
							}
						}
					}
			}

		
		
		
	}



?>