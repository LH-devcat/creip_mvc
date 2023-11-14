<?php

class vue_admin {
	
	static function affichage_admin () {
	if(!isset($_SESSION['rank'])){
		header('location: ../index.php');
	}
	?>
	<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>CVtheque Paris 13</title>
    <!-- core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/font-awesome.min.css" rel="stylesheet">
    <link href="css/animate.min.css" rel="stylesheet">
    <link href="css/owl.carousel.css" rel="stylesheet">
    <link href="css/owl.transitions.css" rel="stylesheet">
    <link href="css/prettyPhoto.css" rel="stylesheet">
    <link href="css/main.css" rel="stylesheet">
    <link href="css/responsive.css" rel="stylesheet">
    <link href="css/modif.css" rel="stylesheet">
    <!--[if lt IE 9]>
    <script src="js/html5shiv.js"></script>
    <script src="js/respond.min.js"></script>
    <![endif]-->
    <link rel="icon" type="image/png" href="images/ico/favicon1.ico" />
    <link rel="shortcut icon" href="images/ico/favicon1.ico" />

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
                    <a class="navbar-brand" href="index.php"><img src="images/logo-P13.png" alt="logo"></a>
                </div>

                <div class="collapse navbar-collapse navbar-right">
                    <ul class="nav navbar-nav">
                        <li class="scroll active"><a href="index.php?module=admin">Mon compte</a></li>
                        <li class="scroll"><a href="#">CVthèque</a></li>
						<li class="scroll"><a href="#">Depot</a></li>
                        <li class="scroll"><a href="#">Paramètre</a></li>
                        <li class="scroll"><a href="index.php?module=deconnexion">Se déconnecter</a></li>
                    </ul>
                </div>
            </div>
            <!--/.container-->
        </nav>
        <!--/nav-->
    </header>
	
    <section id="services">
        <div class="container">

            <div class="section-header">
                <h2 class="section-title text-center wow fadeInDown">Bienvenue</h2>
                <p class="text-center wow fadeInDown"><?php
				echo $_SESSION['login']; ?></p>
            </div>

            <div class="row">
                <div class="features">

                    <div class="col-md-6 col-sm-6 wow fadeInUp" data-wow-duration="300ms" data-wow-delay="100ms">
                        <div class="media service-box">
                            <a href="#">
                                <div class="pull-left">
                                    <i class="fa fa-cloud-upload"></i>
                                </div>
                                <div class="media-body">
                                    <h4 class="media-heading">Mettre en ligne un CV</h4></a>
                            <p>Mettez un CV en ligne à la place d'un étudiant irresponsable</p>
                            </div>
                        </div>
                    </div>
                    <!--/.col-md-4-->

					<div class="col-md-6 col-sm-6 wow fadeInUp" data-wow-duration="300ms" data-wow-delay="200ms">
                        <div class="media service-box">
                            <a href="index.php?module=generateurcode&action=affichForm">
                                <div class="pull-left">
                                    <i class="fa fa-database"></i>
                                </div>
                                <div class="media-body">
                                    <h4 class="media-heading">Générer un code d'activation</h4></a>
                            <p>Générer un code aléatoirement</p>
                            </div>
                        </div>
                    </div>
                    <!--/.col-md-4-->
					
                    <div class="col-md-6 col-sm-6 wow fadeInUp" data-wow-duration="300ms" data-wow-delay="200ms">
                        <div class="media service-box">
                            <a href="#">
                                <div class="pull-left">
                                    <i class="fa fa-times"></i>
                                </div>
                                <div class="media-body">
                                    <h4 class="media-heading">Retirer un CV</h4></a>
                            <p>Supprimez un CV de la base de donnée</p>
                            </div>
                        </div>
                    </div>
                    <!--/.col-md-4-->



                    <div class="col-md-6 col-sm-6 wow fadeInUp" data-wow-duration="300ms" data-wow-delay="400ms">
                        <div class="media service-box">
                            <a href="#">
                                <div class="pull-left">
                                    <i class="fa fa-cog"></i>
                                </div>
                                <div class="media-body">
                                    <h4 class="media-heading">Paramètres</h4></a>
                            <p>Réglez vos paramètres de compte</p>
                            </div>
                        </div>
                    </div>
                    <!--/.col-md-4-->

                    <div class="col-md-6 col-sm-6 wow fadeInUp" data-wow-duration="300ms" data-wow-delay="500ms">
                        <div class="media service-box">
                            <a href="index.php?module=deconnexion.php">
                                <div class="pull-left">
                                    <i class="fa fa-power-off"></i>
                                </div>
                                <div class="media-body">
                                    <h4 class="media-heading">Se déconnecter</h4></a>
                            <p>A bientôt</p>
                            </div>
                        </div>
                    </div>
                    <!--/.col-md-4-->
                </div>
            </div>
            <!--/.row-->
        </div>
        <!--/.container-->
    </section>
    <!--/#services-->
<?php
	}
}
?>
