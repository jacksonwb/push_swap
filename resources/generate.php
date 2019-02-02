#!/usr/bin/env php
<?php
if ($argc == 2 && is_numeric($argv[1]))
{
	$nums = range(0, $argv[1] - 1);
	shuffle($nums);
	$str = implode(" ", $nums);
	echo $str;
}