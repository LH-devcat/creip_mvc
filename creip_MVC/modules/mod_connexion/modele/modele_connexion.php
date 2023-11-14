<?php
	
class modele_connexion{
	
		
		static function getIdUser($pseudo,$pass){	
			require('dns.php');
			$connexion = new PDO ($dns, $user, $password);

			if (isset($_POST['login']) and isset($_POST['password']))
			{
				$passhach = sha1($_POST['password']);														
				$req = $connexion->prepare('SELECT login,rank from connexion where login = ? and password = ?');
				//$req->execute(array($_POST['login'], $passhach));											
				$req->execute(array($_POST['login'], $_POST['password']));	
				$res=$req->fetch(PDO::FETCH_ASSOC);
	
				if (!$res)//Si user avec login et password incorrect
				{
					echo '<div class="login-card">
					<h1>Mot de passe incorrect</h1></br>
					<form action="index.php?module=connexion.php" method="post">
					<input type="text" name="login" placeholder="Identifiant"/>
					<input type="password" name="password" placeholder="Mot de passe"/>
					<input type="submit" class="login login-submit" value="Se connecter"/>
					<a href="mdpOublie.php">Mot de passe oublié ?</a> 
					</form>
					</div>';
					$delai= 2;						
					$url= 'index.php?module=connexion';
					echo "Vous serez redirigé dans $delai secondes";
					header("refresh:2 ; $url");
				}
				else //Si un user avec login et password correct
				{
					$_SESSION['rank']=$res['rank'];
					$_SESSION['login']=$res['login'];
					print_r($_SESSION, true);
					/*echo $_SESSION['login'];
					echo $res['login'];*/
					if($_SESSION['rank']==1){
						
						header('location: index.php?module=admin');
					}
					else{
						
						header('location: index.php');
					}
					
				}
			}
	
		}
		
		static function mdpOublie (){
			
			//SI ENVOI DU FORMULAIRE, EXISTE $_POST
			if (isset($_POST['login']) and isset($_POST['mail']))
			{
			//PREG_MATCH MAIL VALIDE
				$atom = '[-a-z0-9!#$%&\'*+\\/=?^_`{|}~]';
				$domain = '([a-z0-9]([-a-z0-9]*[a-z0-9]+)?)';
				$regexmail = '/^' . $atom . '+' . '(\.' . $atom . '+)*' . '@' . '(' . $domain . '{1,63}\.)+' .$domain . '{2,63}$/i';
			//SI MAIL VALIDE
				if(isset($_POST['mail']) && preg_match($regexmail, $_POST['mail']))
				{
					$req = $connexion->prepare('SELECT password from connexion where login = ? and mail = ?');
					$req->execute(array($_POST['login'], $_POST['mail']));
					$res=$req->fetch(PDO::FETCH_ASSOC);
			//SI IL N'EXISTE PAS UNE PERSONNE AVEC LE LOGIN ET MAIL DEMANDE
					if (!$res)
					{
						echo '<div class="login-card">
						<h1>Login et/ou mail incorrect(s)</h1></br>
						<a href="index.php?module=connexion.php"><p>Retour</p></a>
						</div>';
					}
			//SI EXISTE UNE PERSONNE AVEC LE LOGIN ET MAIL DEMANDE
					else
					{
				//ENVOI DE MAIL
						echo $_POST['mail'] . ' ' . $res['password'];
						mail($_POST['mail'], "Oublie de mot de passe", $res['password']);
						echo '<div class="login-card">
						<h1>Un mail a été envoyé</h1></br>
						<a href="index.php?module=connexion.php"><p>Retour</p></a>
						</div>';
					}
				}
		//MAIL NON VALIDE
			else
			{
				echo '<div class="login-card">
				<h1>Mail non valide</h1></br>
				<a href="index.php?module=connexion.php"><p>Retour</p></a>
				</div>';
			}
			
		
			}
		}
}

?>
			

