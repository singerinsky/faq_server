#!/bin/env python

import sys , os
reload(sys)
sys.setdefaultencoding('utf8')
from config_list import *
import csv


def dump(obj):
    for attr in dir(obj):
        #if attr.startswith('_') or callable(getattr(obj,attr)):
        if attr.startswith('_') :
            continue 
        print "obj.%s=%s" %(attr,getattr(obj,attr))

def read_row_data(record,field_name_list,row_data):
    for i in xrange(len(row_data)):
        if not hasattr(record,field_name_list[i]) :
            continue
        field= getattr(record,field_name_list[i])
        try:
            if isinstance(field,int) :
                setattr(record,field_name_list[i],int(row_data[i]) )
            elif isinstance(field,str) :
                setattr(record,field_name_list[i],(row_data[i]) )
            elif isinstance(field,unicode) :
                setattr(record,field_name_list[i],unicode(row_data[i],"gbk") )
            elif isinstance(field,float) :
                setattr(record,field_name_list[i],float(row_data[i]) )
            else:
                print "unsupported field type %s field_name:%s" % (type(field),field_name_list[i])
                exit()
        
        except ValueError:
            dump(record)
            print record.__str__
            print "invalid value, type:%s %s=%s" %(type(field),field_name_list[i],row_data[i])
            exit()

def read_row_data_v2(record,field_name2index,row_data):
    for field_desc in record.DESCRIPTOR.fields :
        if not field_name2index.has_key(field_desc.name) :
            print "field %s is not set" % (field_desc.name)
            continue

        try:
            i = field_name2index[field_desc.name]
            
            # uncomment below to debug
            #if not row_data[i] :
            #    print "Warn: row %s index %d is empty (you can ignore this message if it's optional)." % (row_data, i)
            #    continue

            if field_desc.type == 2 : # float
                setattr(record,field_desc.name,float(row_data[i]) )
            elif  field_desc.type == 5 : #int
                setattr(record,field_desc.name,int(row_data[i]) )
            elif field_desc.type == 9 : #unicode
                setattr(record,field_desc.name,unicode(row_data[i],"gbk") )
            elif field_desc.type == 12 : #unicode
                setattr(record,field_desc.name,row_data[i] )
            else:
                print "unsupported field type %d field_name:%s" % (field_desc.type,field_desc.name)
                exit()
 
        except ValueError:
            print record.__str__
            print "invalid value, type:%s %s=%s" %(type(field),field_name_list[i],row_data[i])
            exit()
        except Exception as ex:
            print ex

def read_csv_data(repeat_record,reader):
    field_name_list = reader.next()
    field_desc_list = reader.next()
    field_type_list = reader.next()
    field_name2index = {}
    for i in xrange(len(field_name_list)):
        field_name2index[field_name_list[i]] = i
   
    for row_data in reader :
        if len(row_data)!= len(field_name_list) :
            print "mismatched data and field in csvfile %s" % src_file
            exit()
        record = repeat_record.add()
        #read_row_data(record,field_name_list,row_data) 
        #print row_data
        read_row_data_v2(record,field_name2index,row_data)    


def parse_file(parse_config):
    if parse_config[0] == 0 :
        print "parsing %s ......" % parse_config[2]
        data_group = parse_config[1]
        field_desc = data_group.DESCRIPTOR.fields[0]
        if len(data_group.DESCRIPTOR.fields) == 1 and field_desc.type ==11 :
            repeat_record = getattr(data_group,field_desc.name)
            src_file = open(parse_config[2])
            reader = csv.reader(src_file)
            read_csv_data(repeat_record,reader)
            dst_file= open(parse_config[3],"wb")
            dst_file.write(data_group.SerializeToString())
            src_file.close()
            dst_file.close()
            print "write %s success record:%d" %(parse_config[3],len(repeat_record) )
        else:
            print "unsupported group type:" , data_group.DESCRIPTOR.name 
            exit()
    elif parse_config[0] == 1:
        pass
    else:
        print "invalid config:" , parse_config
        exit()

        


def main(argv):
    for parse_config in parse_config_list :
        try:
            parse_file(parse_config)
        except Exception as ex:
            print "parse [%s] failed " % parse_config[2]
            print ex


if __name__ == "__main__":
    try:
        main(sys.argv)
    except KeyboardInterrupt:
        pass
