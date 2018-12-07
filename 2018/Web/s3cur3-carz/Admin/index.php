<html>
<head>
	<title>s3cur3 carz</title>
	<style>
		html
		{
			background-image: url('images/car.jpg');
			background-size: cover;
		}
	</style>
</head>

<body>
<u><center><h1><b>s3cur3 car sh0wr00m</b></h1></center></u>
<br>
This is so far the most s3cur3 carz info dispenser available in the planet. This app has <b>no defect</b> at all.
<br>
This web interface shows the all the top cars from each Automobile company in order of aWsmness of my choice :P
<br><br>

<form action='#' method='post'>
	<label for="id">Car aWsmness Rank: </label>
	<input type="text" id="id" name="id" value="5" required>
	<select name="option">
    		<option value="audi">Audi</option>
		<option value="fiat">Fiat</option>
		<option value="volvo">Volvo</option>
	</select>
	<br><br>
	<input type="submit" name="submit">
</form>
<br><br>
</body>
<?php

include('config.php');

function sanitize($id, $option)
{
	if(!is_numeric($id))
	{
		die("Who are you trying to hack???");
	}

	if($id < 2)
	{
		die("Yeah...Thats the most aWsmst car!!! :)");
	}
    	
	$special1 = ["!", "\"", "#", "$", "%", "&", "'", "*", "+", "-"];
	$special2 = [".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]"];
	$special3 = ["^", "_", "`", "{", "|", "}", "~"];
	$sql1 = ["union", "0", "join", "as", "like", "database", "admin" , "limit", "by", "substr", "mid", "or"];
	$sql2 = ["not", "ascii", "char", "greatest", "regexp", "%00", "benchmark", "in", "and", "if", "where"];
	$sql3 = ["concat", "insert", "having", "sleep", "length", "str", "insert", "between", "except", "ord"];
	$sql4 = ["benchmark", "schema"];
	$blacklist = array_merge ($special1, $special2, $special3, $sql1, $sql2, $sql3, $sql4);

	foreach ($blacklist as $value) 
	{	
		if (stripos($option, $value) !== false)
		{
            		exit("Who are you trying to hack???");
		}
		if (stripos($id, $value) !== false)
		{
			exit("Who are you trying to hack???");
		}
    	}	
}

	
if(isset($_POST['id']) && isset($_POST['option']) && isset($_POST['submit']))
{
	$id = $_POST['id'];
	$option = $_POST['option'];

	sanitize($id, $option);	

	$query = "select ID, CarName from $option where ID = $id";
	# I forgot to print the 'Defect' column :(	
	
	$result = mysqli_query($conn, $query);
	
	$res = mysqli_fetch_array($result);
	
	echo "The aWsmness Rank is: " . $res['ID'];
	echo "<br><br>";
	echo "The Car Name is: " . $res['CarName'];
}	

?>

<br>
</html>



























































<!-- /source.php might be quite interesting -->
