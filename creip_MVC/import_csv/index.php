<?php
// including the config file
include('config.php');
$pdo = connect();
// select all members
$sql = 'SELECT * FROM etudiant ORDER BY id ASC';
$query = $pdo->prepare($sql);
$query->execute();
$list = $query->fetchAll();
?>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Upload CSV dans la base de donnée</title>
<link rel="stylesheet" href="css/style.css" />
<script type="text/javascript" src="js/jquery.min.js"></script>
<script type="text/javascript" src="js/script.js"></script>
</head>

<body>
    <div class="container">
        <div class="header">
            <img src="images/logo-P13.png" alt="logo-P13" />
        </div><!-- header -->
        <h1 class="main_title">Importer CSV à MySQL et Exporter de MySQL à CSV</h1>
        <div class="content">
            <fieldset class="field_container align_right">
                <legend> <img src="images/arrow.gif"> Opérations</legend>
                <span class="import" onclick="show_popup('popup_upload')">Importer CSV a MySQL</span>
                <a href="export.php" class="export">Exporter de MySQL à CSV</a>
            </fieldset>
            <fieldset class="field_container">
                <legend> <img src="images/arrow.gif"> Liste etudiant </legend>
                <div id="list_container">
                    <table class="table_list" cellspacing="2" cellpadding="0">
                        <tr class="bg_h">
                            <th>id</th>
                            <th>Nom</th>
                            <th>Prenom</th>
                            <th>Filiere</th>
                        </tr>
                        <?php
                            $bg = 'bg_1';
                            foreach ($list as $rs) {
                                ?>
                                <tr class="<?php echo $bg; ?>">
                                    <td><?php echo $rs['id']; ?></td>
                                    <td><?php echo $rs['Nom']; ?></td>
                                    <td><?php echo $rs['Prenom']; ?></td>
                                    <td><?php echo $rs['Filiere']; ?></td>
                                </tr>
                                <?php
                                if ($bg == 'bg_1') {
                                    $bg = 'bg_2';
                                } else {
                                    $bg = 'bg_1';
                                }
                            }
                        ?>
                    </table>
                </div><!-- list_container -->
            </fieldset>
        </div><!-- content -->
        <div class="footer">
            CVtheque Paris 13
        </div><!-- footer -->
    </div><!-- container -->

    <!-- la popoup qui zoom pour uploader le fichier csv -->
    <div id="popup_upload">
        <div class="form_upload">
            <span class="close" onclick="close_popup('popup_upload')">x</span>
            <h2>Uploader un fichier CSV</h2>
            <form action="import.php" method="post" enctype="multipart/form-data">
                <input type="file" name="csv_file" id="csv_file" class="file_input">
                <input type="submit" value="Upload file" id="upload_btn">
            </form>
        </div>
    </div>
</body>
</html>
