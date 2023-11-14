<?php
//require('creip_MVC/header.php');
	 class vue_activercode {
		
		static function affichVue_activercode ($donnee){
			

			
			echo "<body>
				<section id=\"about\">
					<div class=c\"ontainer\">
						<div class=\"section-header\">
							<h2 class=\"section-title text-center wow fadeInDown\">Activer un code</h2>
							<form method=\"POST\" action=\"index.php?module=activercode\" enctype=\"multipart/form-data\">
							<p class=\"text-center wow fadeInDown\"><br>
							<input placeholder=\"Code\" type=\"text\" name=\"code\"></input><br><br>
							<input class=\"btn btn-primary\" type=\"submit\" name=\"Activer\" value=\"Activer\"></p>
							</form>";
		}
		
		
	}



?>