#!/bin/env python

import sys , os
reload(sys)
sys.setdefaultencoding('utf8')

from config_list import *
import csv


def dump_file(parse_config,bin_file):
    reader = open(bin_file,"rb")
    data_group = parse_config[1]
    data_group.ParseFromString(reader.read())
    field_desc = data_group.DESCRIPTOR.fields[0]
    repeat_record = getattr(data_group,field_desc.name)
    if len(repeat_record) < 1 :
        return
    
    for field_desc in repeat_record[0].DESCRIPTOR.fields :
        print "%s," % field_desc.name ,
    print ""
    
    for record in repeat_record :
        for field_desc in record.DESCRIPTOR.fields :
            if field_desc.type == 2 : # float
                print "%f , " % getattr(record,field_desc.name ),
            elif  field_desc.type == 5 : #int
                print "%d , " % getattr(record,field_desc.name ),
            elif field_desc.type == 9 : #unicode
                print "%s , " % getattr(record,field_desc.name ),
            elif field_desc.type == 12 : #unicode
                print "%s , " % getattr(record,field_desc.name ),
            else:
                print "unknown,", 
               
        
        print ""
            


def main(argv):
    if len(argv) < 2 :
        print "usage:%s file" % argv[0]
    for parse_config in parse_config_list :
        if os.path.basename(parse_config[3]) == os.path.basename(argv[1]) :
            dump_file(parse_config,argv[1])


if __name__ == "__main__":
    try:
        main(sys.argv)
    except KeyboardInterrupt:
        pass
