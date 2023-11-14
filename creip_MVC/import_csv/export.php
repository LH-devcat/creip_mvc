<?php
include('config.php');
$pdo = connect();

// exportation des elements dans la bdd en formats csv
header('Content-Type: text/csv; charset=utf-8');
header('Content-Disposition: attachment; filename=etudiant.csv');

// on initialise les elements qu'il a dans bdd cvtheque.
$output = "id,User,Nom,Prenom,Filiere\n";
// on selectionne tout les membres rangé par ordre croissant 
$sql = 'SELECT * FROM etudiant ORDER BY id ASC';
$query = $pdo->prepare($sql);// on prepare la requete
$query->execute();
$list = $query->fetchAll();
foreach ($list as $rs) {
	// on recupere les elements qu'il y'a
    $output .= $rs['id'].",".$rs['User'].",".$rs['Nom'].",".$rs['Prenom'].",".$rs['Filiere']."\n";
}
// un fichier csv est donc crée et on peut le telecharger.
echo $output;
exit;
?>


