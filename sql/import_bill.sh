#!/bin/sh

#set -x

# daily bill log file is under log_server/bill-2013-03-13.log 
echo "Attention: Please run this shell under deploy/log_server"

# get yesterday date
yesterday=`date -d"1 day ago" +"%Y-%m-%d"`

# log file name
log_file_name="bill-$yesterday.log"

# test yesterday bill log is exists
if [ -e $log_file_name ] 
then
    echo "Import $log_file_name data to Database knight_bill table trans_bill"
else
    echo "No data to import."
    exit 
fi

# rename file to tablename , for mysqlimport need
mv $log_file_name trans_bill.log


# method 1: file name should be trans_bill.* trans_bill is the table name

 mysqlimport -uroot --local --fields-terminated-by='|' --lines-terminated-by='\n' --columns=bill_time,seq,role_id,name,role_level,job_type,channel,trans_type,money_type,money_change_value,money_left_value,item_id,item_count -v  knight_bill trans_bill.log 

# method 2 , file name doesn't need to be same with table name, but need put in specific path
#echo "Usage: $0 data_file_path"
#echo "Data file path should with mysql privileges ,better in /tmp/ directory"

#mysql -uroot knight_bill -e "LOAD DATA INFILE '$1' INTO TABLE trans_bill \
#FIELDS TERMINATED BY '|' LINES TERMINATED BY '\n' (bill_time,seq,role_id,name,role_level,\
#job_type,channel,trans_type,money_type,money_change_value,money_left_value,item_id,\
#item_count) "

