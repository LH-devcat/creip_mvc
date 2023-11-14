<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>CVtheque Paris 13</title>
    <!-- core CSS -->
    <link href="/creip/css/bootstrap.min.css" rel="stylesheet">
    <link href="/creip/css/font-awesome.min.css" rel="stylesheet">
    <link href="/creip/css/animate.min.css" rel="stylesheet">
    <link href="/creip/css/owl.carousel.css" rel="stylesheet">
    <link href="/creip/css/owl.transitions.css" rel="stylesheet">
    <link href="/creip/css/prettyPhoto.css" rel="stylesheet">
    <link href="/creip/css/main.css" rel="stylesheet">
    <link href="/creip/css/responsive.css" rel="stylesheet">
    <link href="/creip/css/modif.css" rel="stylesheet">
	<link rel="stylesheet" href="/creip/css/owl.carousel.css">
	<link rel="stylesheet" href="/creip/css/owl.theme.css">
	<script src="/creip/js/jquery.js"></script>
	<script src="/creip/js/owlcarousel/owl.carousel.min.js"></script>
	<link rel="stylesheet" href="/creip/css/owl.theme.default.min.css">
    <!--[if lt IE 9]>
    <script src="js/html5shiv.js"></script>
    <script src="js/respond.min.js"></script>
    <![endif]-->
    <link rel="icon" type="image/png" href="/creip/images/ico/favicon1.ico" />
    <link rel="shortcut icon" href="/creip/images/ico/favicon1.ico" />

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
                    <a class="navbar-brand" href="index.php"><img src="/creip/images/logo-P13.png" alt="logo"></a>
                </div>
				
                <div class="collapse navbar-collapse navbar-right">
                    <ul class="nav navbar-nav">
						<?php 
							ini_set("display_errors",1);
							 if(basename($_SERVER['PHP_SELF'])=='index.php')
							 {
								echo "<li class='scroll  active'><a href='/creip_MVC/index.php'>Accueil</a></li>
								<li class='scroll'><a href='/creip_MVC/modules/mod_activercode/activercode.php'>Activer un code</a></li>";
							 }else{
								echo "<li class='scroll'><a href='/creip_MVC/index.php'>Accueil</a></li>
							<li class='scroll active'><a href='/creip/activercode.php'>Activer un code</a></li>";
							 }
						?>
                        <li class="scroll"><a href="connexion.php">Se connecter</a></li>
                    </ul>
                </div>
            </div>
            <!--/.container-->
        </nav>
        <!--/nav-->
    </header>