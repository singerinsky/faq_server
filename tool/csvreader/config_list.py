#!/bin/env python
import sys , os
reload(sys)
#sys.path.append('/home/gl/faq_server/tool/csvreader/python')
sys.path.append('./python')

from npc_data_pb2 import NpcDataGroup 
parse_config_list = [
    (0,NpcDataGroup(),"template.csv/npc_data.csv","streams/npc_data.bin")
]



