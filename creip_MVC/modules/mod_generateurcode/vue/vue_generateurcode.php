<?php

class vue_generateurcode {
	
	static function form_Generer_Code (){
		
	?>	
	<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>CVthèque Paris 13</title>
	<!-- core CSS -->
    <link href="../css/bootstrap.min.css" rel="stylesheet">
    <link href="../css/font-awesome.min.css" rel="stylesheet">
    <link href="../css/animate.min.css" rel="stylesheet">
    <link href="../css/owl.carousel.css" rel="stylesheet">
    <link href="../css/owl.transitions.css" rel="stylesheet">
    <link href="../css/prettyPhoto.css" rel="stylesheet">
    <link href="../css/main.css" rel="stylesheet">
    <link href="../css/responsive.css" rel="stylesheet">
    <!--[if lt IE 9]>
    <script src="js/html5shiv.js"></script>
    <script src="js/respond.min.js"></script>
    <![endif]-->
    <link rel="icon" type="image/png" href="../images/ico/favicon1.ico"/>
    <link rel="shortcut icon" href="../images/ico/favicon1.ico"/>
    
</head><!--/head-->

<body id="home" class="homepage">

    <header id="header">
        <nav id="main-menu" class="navbar navbar-default navbar-fixed-top" role="banner">
            <div class="container">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="../index.php"><img src="../images/logo-P13.png" alt="logo"></a>
                </div>
				
                <div class="collapse navbar-collapse navbar-right">
                    <ul class="nav navbar-nav">
                        <li class="scroll"><a href="#">À propos</a></li>
                        <li class="scroll"><a href="#">Contact</a></li>                        
                    </ul>
                </div>
            </div><!--/.container-->
        </nav><!--/nav-->
    </header><!--/header-->
    
    <section id="about">
        <div class="container">
            <div class="section-header">
                <h2 class="section-title text-center wow fadeInDown">Générer des codes d'activation</h2>
                <p class="text-center wow fadeInDown">
				<center>
				<form method="POST" action="index.php?module=generateurcode&action=generercode" enctype="multipart/form-data">
					
					</br>
					Nombre de codes a générer : <input type='text' Name='nbrCodes' value='1'><br>
					Type de compte: <input type="radio" name="Type" value="0" CHECKED> Etudiant <input type="radio" name="Type" value="1"> Administrateur
					<br></br>
					<input class="btn btn-primary" type="submit" name="Générer" value="Générer">
				</form>
		</center></p>
            </div>
        </div>
    </section>
		
	<?php	
	}
	
	
	
}


?>
