<?php
ini_set("display_errors",1);
define('TEST_INCLUDE', 1);
session_start();
?>
<!DOCTYPE html>
<html lang="fr">

	<?php
		if (empty($_GET['module'])){
			$module ='accueil';
		}
		else{
			$module = $_GET['module'];
		}

	
	
?>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>CVtheque Paris 13</title>
    <!-- core CSS -->
    <link href="/creip_MVC/css/bootstrap.min.css" rel="stylesheet">
    <link href="/creip_MVC/css/font-awesome.min.css" rel="stylesheet">
    <link href="/creip_MVC/css/animate.min.css" rel="stylesheet">
    <link href="/creip_MVC/css/owl.carousel.css" rel="stylesheet">
    <link href="/creip_MVC/css/owl.transitions.css" rel="stylesheet">
    <link href="/creip_MVC/css/prettyPhoto.css" rel="stylesheet">
    <link href="/creip_MVC/css/main.css" rel="stylesheet">
    <link href="/creip_MVC/css/responsive.css" rel="stylesheet">
    <link href="/creip_MVC/css/modif.css" rel="stylesheet">
	<link rel="stylesheet" href="/creip_MVC/css/owl.carousel.css">
	<link rel="stylesheet" href="/creip_MVC/css/owl.theme.css">
	<script src="/creip_MVC/js/jquery.js"></script>
	<script src="/creip_MVC/js/owlcarousel/owl.carousel.min.js"></script>
	<link rel="stylesheet" href="/creip_MVC/css/owl.theme.default.min.css">
    <!--[if lt IE 9]>
    <script src="js/html5shiv.js"></script>
    <script src="js/respond.min.js"></script>
    <![endif]-->
    <link rel="icon" type="image/png" href="/creip_MVC/images/ico/favicon1.ico" />
    <link rel="shortcut icon" href="/creip_MVC/images/ico/favicon1.ico" />

</head>
<!--/head-->

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
                    <a class="navbar-brand" href="index.php"><img src="/creip_MVC/images/logo-P13.png" alt="logo"></a>
                </div>
				
                <div class="collapse navbar-collapse navbar-right">
                    <ul class="nav navbar-nav">
						<?php 
						include "modules/mod_$module/$module.php";
							 if(basename($_SERVER['PHP_SELF'])=='index.php')
							 {
								 
								echo "<li class='scroll'><a href='/creip_MVC/index.php'>Accueil</a></li>
							<li class='scroll active'><a href='index.php?module=activercode'>Activer un code</a></li>";
							 }
						?>
                        <li class="scroll"><a href="index.php?module=connexion">Se connecter</a></li>
                    </ul>
                </div>
            </div>
            <!--/.container-->
        </nav>
        <!--/nav-->
    </header>
	
	<section id="portfolio">
<div class="container">
<div class="section-header">
<h2 class="section-title text-center wow fadeInDown">CVThèque Paris 13</h2>
<p class="text-center wow fadeInDown">Bienvenue dans la CVThèque Paris 13, un espace de recherche de stages, et de stagiaires.</p>
</div>
<div class="text-center">
<ul class="portfolio-filter">
<li><a onclick="Show()" href="#" data-filter=".student">Etudiant</a></li>
<li><a onclick="Show()" href="#" data-filter=".company">Entreprise</a></li>
<li><a onclick="Show()" href="#" data-filter=".admin">Responsable</a></li>
</ul> 
</div>
<div id="hidden" hidden>
<center>
<div class="portfolio-items">
<div class="portfolio-item student">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/application.png" alt=""></center>
<div class="portfolio-info">
<h3>Suivez votre CV</h3>
Soumettez votre CV et améliorez le
</div>
</div>
</div> 

<div class="portfolio-item student">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/business.png" alt=""></center>
<div class="portfolio-info">
<h3>Obtenez des entretiens</h3>
Une offre adaptée à vos compétences
</div>
</div>
</div> 

<div class="portfolio-item company">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/square.png" alt=""></center>
<div class="portfolio-info">
<h3>Déposez des offres</h3>
Et spécifiez vos besoins
</div>
</div>
</div> 

<div class="portfolio-item company">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/tool.png" alt=""></center>
<div class="portfolio-info">
<h3>Trouvez des stagiaires</h3>
Des profils adaptés à vos recherches
</div>
</div>
</div> 

<div class="portfolio-item admin">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/assist.png" alt=""></center>
<div class="portfolio-info">
<h3>Assistez les étudiants et les entreprises</h3>
Dans la recherche et l'offre de stage
</div>
</div>
</div> 

<div class="portfolio-item admin">
<div style="height:200px;" class="portfolio-item-inner">
    <center><img class="img-responsive" src="images/portfolio/order.png" alt=""></center>
<div class="portfolio-info">
<h3>Approuvez les envois</h3>
D'offres et de CV
</div>
</div>
</div> 
</div>
</center>
</div>
</div> 
</section> 
<script>function Show(){
    document.getElementById("hidden").style.display = 'block';
};</script>
	
	<footer>
    <?php include( "footer.php"); ?></footer>
</html>