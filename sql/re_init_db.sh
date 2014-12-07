
echo "drop database knight_lianyun"
mysql -uroot -e "drop database if exists knight_lianyun"

echo "create database knight_lianyun"
mysql -uroot -e "CREATE DATABASE IF NOT EXISTS knight_lianyun DEFAULT CHARACTER SET utf8 ;"

echo "import game.sql"
mysql -uroot knight_lianyun < game.sql

echo "database init finished!"

