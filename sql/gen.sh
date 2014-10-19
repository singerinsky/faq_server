#!/bin/bash
if [ -d orm_object ] ; then
    php ./orm.php localhost root "firefly" faq_server tb_user orm_object/
    #cp omg_sql/* ../orm/
else
        echo "dir [omg_sql] not exist"
    fi

