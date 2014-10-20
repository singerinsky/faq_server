#!/bin/bash
if [ -d ../message ] ; then
    php ./orm.php localhost root "firefly" faq_server tb_user ../message/ 
    #cp omg_sql/* ../orm/
else
        echo "dir [omg_sql] not exist"
    fi

