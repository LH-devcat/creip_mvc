<?php 
// 
include('config.php');
$pdo = connect();

$csv_file =  $_FILES['csv_file']['tmp_name'];
if (is_file($csv_file)) {
	$input = fopen($csv_file, 'a+');
	// 
	$row = fgetcsv($input, 1024, ';'); 
	while ($row = fgetcsv($input, 1024, ';')) {
		// Inserer dans la base de donnée les elements sur csv
		$sql = 'INSERT INTO etudiant(id, Nom, Prenom, Filiere) VALUES(:id, :Nom, :Prenom, :Filiere)';
		$query = $pdo->prepare($sql);
		$query->bindParam(':id', $row[1], PDO::PARAM_STR);
		$query->bindParam(':Nom', $row[2], PDO::PARAM_STR);
		$query->bindParam(':Prenom', $row[3], PDO::PARAM_STR);
		$query->bindParam(':Filiere', $row[4], PDO::PARAM_INT);
		$query->execute();
	}
}

// redirection la page d'acceuil
header('location: index.php');
?>


