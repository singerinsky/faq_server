# -*- coding: utf-8 -*-
import sys
reload(sys)
sys.setdefaultencoding('utf8')

import csv
# for each csv file, read it 
# then set template value to 
# python pb config object 
# then save the bin stream to files

# Just one line data to parse
# from python.character_growup_pb2 import CharacterGrowupRate
from python.level_experience_pb2 import LevelExperienceGroup
from python.level_experience_pb2 import LevelExperience
# multi line data to parse
from python.player_init_data_pb2 import PlayerInitData, PlayerInitDataGroup
from python.yingling_init_data_pb2 import YinglingInitData, YinglingInitDataGroup
from python.character_profession_growup_pb2 import CharacterProGrowRate, CharacterProGrowRateGroup
from python.yingling_profession_growup_pb2 import YinglingProGrownRate, YinglingProGrownRateGroup
from python.player_attribute_transit_rate_pb2 import PlayerAttrTransition, PlayerAttrTransitGroup

# repeated line data
from python.creature_init_data_pb2 import CreatureInitData, CreatureInitDataGroup
from python.item_pb2 import PropsData, PropsDataGroup
from python.equipment_pb2 import EquipmentData, EquipmentDataGroup
from python.stone_pb2 import StoneData, StoneDataGroup
from python.magic_item_pb2 import MagicItemData, MagicItemGroup
#from python.npc_pb2 import NPCData, NPCDataGroup
from python.battle_npc_pb2 import BattleNPCData, BattleNPCGroup
from python.battle_group_pb2 import BattleGroupData, BattleGroupArray
from python.skills_pb2 import SkillData, SkillDataGroup
from python.skillbook_pb2 import SkillBookData, SkillBookDataGroup
from python.skill_practice_mode_pb2 import SkillPracticeModeData, SkillPracticeModeDataGroup
from python.shop_pb2 import ShopData, ShopDataGroup
from python.equipment_property_bag_pb2 import ConfigEquipmentProperty, ConfigEquipmentPropertyBag
from python.drop_items_pb2 import DropItemData, DropItemDataGroup
from python.monster_amount_limit_pb2 import MonsterRandomAmountData, MonsterRandomAmountDataGroup
from python.random_battle_group_pb2 import RandomBattleGroupData, RandomBattleGroupDataGroup
from python.transport_pb2 import TransportData,TransportDataGroup 
from python.character_exp_pb2 import CharacterExpData, CharacterExpDataGroup
from python.instance_pb2 import InstanceData,InstanceDataGroup 
from python.soul_injection_pb2 import InjectSoulData, InjectSoulDataGroup
from python.spacetime_battle_pb2 import SpaceTimeBattleData, SpaceTimeBattleDataGroup
from python.equipment_strength_pb2 import EquipmentStrengthData, EquipmentStrengthDataGroup
from python.equipment_xilian_pb2 import EquipmentXilianData, EquipmentXilianDataGroup
from python.daily_quest_pb2 import DailyQuestCategoryData, DailyQuestCategoryDataGroup, DailyQuestLibData, DailyQuestLibDataGroup
from python.daily_quest_pb2 import DailyQuestRewardData, DailyQuestRewardDataGroup
from python.daily_limit_count_pb2 import DailyLimitCooldownData, DailyLimitCooldownDataGroup
from python.daily_limit_count_pb2 import DailyLimitPurchaseData, DailyLimitPurchaseDataGroup
from python.daily_limit_count_pb2 import DailyLimitCountData, DailyLimitCountDataGroup
from python.daily_limit_count_pb2 import DailyLimitCooldownClearData, DailyLimitCooldownClearDataGroup

from python.instance_npc_pb2 import InstanceNPCData,InstanceNPCDataGroup 

from python.buy_challenge_times_cost_pb2 import BuyChallengeTimesCostData, BuyChallengeTimesCostDataGroup
from python.buy_clear_cd_cost_pb2 import BuyClearCDCostData, BuyClearCDCostDataGroup
from python.challenge_bonus_pb2 import ChallengeBonusData, ChallengeBonusDataGroup
from python.challenge_cont_win_title_pb2 import ChallengeContWinTitleData, ChallengeContWinTitleDataGroup
from python.challenge_rank_title_pb2 import ChallengeRankTitleData, ChallengeRankTitleDataGroup
from python.treasure_box_pb2 import TreasureBoxData, TreasureBoxDataGroup
from python.yingling_hiring_config_pb2 import YinglingHiringSlotData, YinglingHiringSlotDataGroup
from python.yingling_hiring_config_pb2 import YinglingHiringConfigData, YinglingHiringConfigDataGroup
from python.yingling_hiring_config_pb2 import YinglingSlotData, YinglingSlotDataGroup
from python.yingling_lingli_pb2 import YinglingLingliConvertData, YinglingLingliConvertDataGroup
from python.yingling_lingli_pb2 import YinglingLingliSummonData, YinglingLingliSummonDataGroup
from python.item_gift_pb2 import ItemGiftData,ItemGiftDataGroup 
from python.item_yingling_pb2 import ItemYinglingData,ItemYinglingDataGroup
from python.random_name_pb2 import RandNameData, RandNameDataGroup
from python.resource_pb2 import ResourceData, ResourceDataGroup
from python.hide_npc_pb2 import DefaultHideNpcData, DefaultHideNpcDataGroup
from python.hide_npc_pb2 import QuestHideNpcData, QuestHideNpcDataGroup
from python.vip_bonus_pb2 import VipBonusData, VipBonusDataGroup
from python.online_time_bonus_pb2 import OnlineTimeBonusData, OnlineTimeBonusDataGroup
from python.team_fight_exp_factor_pb2 import TeamFightExpFactorData, TeamFightExpFactorDataGroup
from python.auto_skip_fight_time_limit_pb2 import AutoSkipFightTimeLimitData, AutoSkipFightTimeLimitDataGroup
from python.fight_cooldown_limit_pb2 import FightCoolDownLimitData, FightCoolDownLimitDataGroup
from python.pay_by_type_cost_pb2 import PayByTypeData, PayByTypeDataGroup
from python.instance_treasure_exchange_pb2 import InstanceTreasureData,InstanceTreasureDataGroup 
from python.gift_pb2 import GiftPackData, GiftPackDataGroup
from python.gift_pb2 import GiftDailyData, GiftDailyDataGroup

csvbasedir = "template.csv"
csvfiles = [
        # singleline csv files
        "character_exp.csv",
        # multi lines 
        "player_init_data.csv",
        "character_profession_growup.csv",
        "yingling_profession_growup.csv",
        "player_attribute_transit_rate.csv",
        # repeated read
        "yingling_init_data.csv",
        "creature_init_data.csv",
        "item.csv",
        "equipment.csv",
        "stone.csv",
        "magic_items.csv",
        #"npc.csv",
        "battle_npc.csv",
        "battle_group.csv",
        "skills.csv",
        "skillbook.csv",
        "skill_practice_mode.csv",
        "shop.csv",
        "market.csv",
        "equip_property_bag.csv",
        "drop_items.csv",
        "monster_amount_limit.csv",
        "random_battle_group.csv" ,
        "transport.csv",
        "character_exp.csv",
        "instance.csv",
        "soul_injection.csv",
        "spacetime_battle.csv",
        "equipment_strength.csv",
        "equipment_xilian.csv",
        "daily_quest_category.csv",
        "daily_quest_lib.csv",
        "daily_quest_reward.csv",
        "daily_limit_cooldown.csv",
        "daily_limit_cooldown_clear.csv",
        "daily_limit_purchase.csv",
        "daily_limit_count.csv",        
        "instance_npc.csv",
        "buy_challenge_times_cost.csv",
        "buy_clear_cd_cost.csv",
        "challenge_bonus.csv",
        "challenge_cont_win_title.csv",
        "challenge_rank_title.csv",
        "treasure_box.csv",
        "yingling_hiring_slot.csv",
        "yingling_hiring_cost.csv",
        "yingling_slot.csv",
        "yingling_lingli_convert.csv",
        "yingling_lingli_summon.csv",
        "item_gift.csv",
        "item_yingling.csv",
        "random_name.csv",
        "resource.csv",
        "hide_npc_default.csv",
        "hide_npc_quest.csv",
        "vip_bonus.csv",
        "gift_pack.csv",
        "gift_daily.csv",
        "online_time_bonus.csv",
        "team_fight_exp_factor.csv",
        "auto_skip_fight_time_limit.csv",
        "fight_cooldown_limit.csv",
        "pay_by_type_cost.csv",
        "instance_treasure_exchange.csv",
        ] 

# 1 for single line
# 2 for multiline but separate in group message
# 3 for multiline but repeated in group message
csvfiletype = [
        3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3,
        ]


binbasedir = "streams"
binfiles = [
        "character_exp.bin",
        # multi lines 
        "player_init_data.bin",
        "character_profession_growup.bin",
        "yingling_profession_growup.bin",
        "player_attribute_transit_rate.bin",
        # repeated multi line
        "yingling_init_data.bin",
        "creature_init_data.bin",
        "item.bin",
        "equipment.bin",
        "stone.bin",
        "magic_items.bin",
        #"npc.bin",
        "battle_npc.bin",
        "battle_group.bin",
        "skills.bin",
        "skillbook.bin",
        "skill_practice_mode.bin",
        "shop.bin",
        "market.bin",
        "equip_property_bag.bin",
        "drop_items.bin",
        "monster_amount_limit.bin",
        "random_battle_group.bin",
        "transport.bin",
        "character_exp.bin",
        "instance.bin",
        "soul_injection.bin",
        "spacetime_battle.bin",
        "equipment_strength.bin",
        "equipment_xilian.bin",
        "daily_quest_category.bin",
        "daily_quest_lib.bin",
        "daily_quest_reward.bin",
        "daily_limit_cooldown.bin",
        "daily_limit_cooldown_clear.bin",
        "daily_limit_purchase.bin",
        "daily_limit_count.bin",
        "instance_npc.bin",
        "buy_challenge_times_cost.bin",
        "buy_clear_cd_cost.bin",
        "challenge_bonus.bin",
        "challenge_cont_win_title.bin",
        "challenge_rank_title.bin",
        "treasure_box.bin",
        "yingling_hiring_slot.bin",
        "yingling_hiring_cost.bin",
        "yingling_slot.bin",
        "yingling_lingli_convert.bin",
        "yingling_lingli_summon.bin",
        "item_gift.bin",
        "item_yingling.bin",
        "random_name.bin",
        "resource.bin",
        "hide_npc_default.bin",
        "hide_npc_quest.bin",
        "vip_bonus.bin",
        "gift_pack.bin",
        "gift_daily.bin",
        "online_time_bonus.bin",
        "team_fight_exp_factor.bin",
        "auto_skip_fight_time_limit.bin",
        "fight_cooldown_limit.bin",
        "pay_by_type_cost.bin",
        "instance_treasure_exchange.bin",
        ]
# 一级 fields
groupfields = [
        # singleline without group fields
        LevelExperienceGroup.DESCRIPTOR.fields,
        # multiline
        PlayerInitDataGroup.DESCRIPTOR.fields,
        CharacterProGrowRateGroup.DESCRIPTOR.fields,
        YinglingProGrownRateGroup.DESCRIPTOR.fields,
        PlayerAttrTransitGroup.DESCRIPTOR.fields,

        # repeated line
        YinglingInitDataGroup.DESCRIPTOR.fields,
        CreatureInitDataGroup.DESCRIPTOR.fields,
        PropsDataGroup.DESCRIPTOR.fields,
        EquipmentDataGroup.DESCRIPTOR.fields,
        StoneDataGroup.DESCRIPTOR.fields,
        MagicItemGroup.DESCRIPTOR.fields,
        #NPCDataGroup.DESCRIPTOR.fields,
        BattleNPCGroup.DESCRIPTOR.fields,
        BattleGroupArray.DESCRIPTOR.fields,
        SkillDataGroup.DESCRIPTOR.fields,
        SkillBookDataGroup.DESCRIPTOR.fields,
        SkillPracticeModeDataGroup.DESCRIPTOR.fields,
        ShopDataGroup.DESCRIPTOR.fields,
        ShopDataGroup.DESCRIPTOR.fields,
        ConfigEquipmentPropertyBag.DESCRIPTOR.fields,
        DropItemDataGroup.DESCRIPTOR.fields,
        MonsterRandomAmountDataGroup.DESCRIPTOR.fields,
        RandomBattleGroupDataGroup.DESCRIPTOR.fields,
        TransportDataGroup.DESCRIPTOR.fields,
        CharacterExpDataGroup.DESCRIPTOR.fields,
        InstanceDataGroup.DESCRIPTOR.fields,
        InjectSoulDataGroup.DESCRIPTOR.fields,
        SpaceTimeBattleDataGroup.DESCRIPTOR.fields,
        EquipmentStrengthDataGroup.DESCRIPTOR.fields,
        EquipmentXilianDataGroup.DESCRIPTOR.fields,
        DailyQuestCategoryDataGroup.DESCRIPTOR.fields,
        DailyQuestLibDataGroup.DESCRIPTOR.fields,
        DailyQuestRewardDataGroup.DESCRIPTOR.fields,
        DailyLimitCooldownDataGroup.DESCRIPTOR.fields,
        DailyLimitCooldownClearDataGroup.DESCRIPTOR.fields,
        DailyLimitPurchaseDataGroup.DESCRIPTOR.fields,
        DailyLimitCountDataGroup.DESCRIPTOR.fields,
        InstanceNPCDataGroup.DESCRIPTOR.fields,
        
        BuyChallengeTimesCostDataGroup.DESCRIPTOR.fields,
        BuyClearCDCostDataGroup.DESCRIPTOR.fields,
        ChallengeBonusDataGroup.DESCRIPTOR.fields,
        ChallengeContWinTitleDataGroup.DESCRIPTOR.fields,
        ChallengeRankTitleDataGroup.DESCRIPTOR.fields,
        TreasureBoxDataGroup.DESCRIPTOR.fields,
        YinglingHiringSlotDataGroup.DESCRIPTOR.fields,
        YinglingHiringConfigDataGroup.DESCRIPTOR.fields,
        YinglingSlotDataGroup.DESCRIPTOR.fields,
        YinglingLingliConvertDataGroup.DESCRIPTOR.fields,
        YinglingLingliSummonDataGroup.DESCRIPTOR.fields,
        ItemGiftDataGroup.DESCRIPTOR.fields,
        ItemYinglingDataGroup.DESCRIPTOR.fields,
        RandNameDataGroup.DESCRIPTOR.fields,
        ResourceDataGroup.DESCRIPTOR.fields,
        DefaultHideNpcDataGroup.DESCRIPTOR.fields,
        QuestHideNpcDataGroup.DESCRIPTOR.fields,
        VipBonusDataGroup.DESCRIPTOR.fields,
        GiftPackDataGroup.DESCRIPTOR.fields,
        GiftDailyDataGroup.DESCRIPTOR.fields,
        OnlineTimeBonusDataGroup.DESCRIPTOR.fields,
        TeamFightExpFactorDataGroup.DESCRIPTOR.fields,
        AutoSkipFightTimeLimitDataGroup.DESCRIPTOR.fields,
        FightCoolDownLimitDataGroup.DESCRIPTOR.fields,
        PayByTypeDataGroup.DESCRIPTOR.fields,
        InstanceTreasureDataGroup.DESCRIPTOR.fields,
        ]

# 二级 fields
fields = [
        LevelExperience.DESCRIPTOR.fields,
        
        PlayerInitData.DESCRIPTOR.fields,
        CharacterProGrowRate.DESCRIPTOR.fields,
        YinglingProGrownRate.DESCRIPTOR.fields,
        PlayerAttrTransition.DESCRIPTOR.fields,

        YinglingInitData.DESCRIPTOR.fields,
        CreatureInitData.DESCRIPTOR.fields,
        PropsData.DESCRIPTOR.fields,
        EquipmentData.DESCRIPTOR.fields,
        StoneData.DESCRIPTOR.fields,
        MagicItemData.DESCRIPTOR.fields,
        #NPCData.DESCRIPTOR.fields,
        BattleNPCData.DESCRIPTOR.fields,
        BattleGroupData.DESCRIPTOR.fields,
        SkillData.DESCRIPTOR.fields,
        SkillBookData.DESCRIPTOR.fields,
        SkillPracticeModeData.DESCRIPTOR.fields,
        ShopData.DESCRIPTOR.fields,
        ShopData.DESCRIPTOR.fields,
        ConfigEquipmentProperty.DESCRIPTOR.fields,
        DropItemData.DESCRIPTOR.fields,
        MonsterRandomAmountData.DESCRIPTOR.fields,
        RandomBattleGroupData.DESCRIPTOR.fields,
        TransportData.DESCRIPTOR.fields,
        CharacterExpData.DESCRIPTOR.fields,
        InstanceData.DESCRIPTOR.fields,
        InjectSoulData.DESCRIPTOR.fields,
        SpaceTimeBattleData.DESCRIPTOR.fields,
        EquipmentStrengthData.DESCRIPTOR.fields,
        EquipmentXilianData.DESCRIPTOR.fields,
        DailyQuestCategoryData.DESCRIPTOR.fields,
        DailyQuestLibData.DESCRIPTOR.fields,
        DailyQuestRewardData.DESCRIPTOR.fields,
        DailyLimitCooldownData.DESCRIPTOR.fields,
        DailyLimitCooldownClearData.DESCRIPTOR.fields,
        DailyLimitPurchaseData.DESCRIPTOR.fields,
        DailyLimitCountData.DESCRIPTOR.fields,
        InstanceNPCData.DESCRIPTOR.fields,
        
        BuyChallengeTimesCostData.DESCRIPTOR.fields,
        BuyClearCDCostData.DESCRIPTOR.fields,
        ChallengeBonusData.DESCRIPTOR.fields,
        ChallengeContWinTitleData.DESCRIPTOR.fields,
        ChallengeRankTitleData.DESCRIPTOR.fields,
        TreasureBoxData.DESCRIPTOR.fields,
        YinglingHiringSlotData.DESCRIPTOR.fields,
        YinglingHiringConfigData.DESCRIPTOR.fields,
        YinglingSlotData.DESCRIPTOR.fields,
        YinglingLingliConvertData.DESCRIPTOR.fields,
        YinglingLingliSummonData.DESCRIPTOR.fields,
        ItemGiftData.DESCRIPTOR.fields,
        ItemYinglingData.DESCRIPTOR.fields,
        RandNameData.DESCRIPTOR.fields,
        ResourceData.DESCRIPTOR.fields,
        DefaultHideNpcData.DESCRIPTOR.fields,
        QuestHideNpcData.DESCRIPTOR.fields,
        VipBonusData.DESCRIPTOR.fields,
        GiftPackData.DESCRIPTOR.fields,
        GiftDailyData.DESCRIPTOR.fields,
        OnlineTimeBonusData.DESCRIPTOR.fields,
        TeamFightExpFactorData.DESCRIPTOR.fields,
        AutoSkipFightTimeLimitData.DESCRIPTOR.fields,
        FightCoolDownLimitData.DESCRIPTOR.fields,
        PayByTypeData.DESCRIPTOR.fields,
        InstanceTreasureData.DESCRIPTOR.fields,
        ]

# 一级 instance
groupInst = [
        LevelExperienceGroup(),
        # multi-line
        PlayerInitDataGroup(),
        CharacterProGrowRateGroup(),
        YinglingProGrownRateGroup(),
        PlayerAttrTransitGroup(),
        # repeated 
        YinglingInitDataGroup(),
        CreatureInitDataGroup(),
        PropsDataGroup(),
        EquipmentDataGroup(),
        StoneDataGroup(),
        MagicItemGroup(),
        #NPCDataGroup(),
        BattleNPCGroup(),
        BattleGroupArray(),
        SkillDataGroup(),
        SkillBookDataGroup(),
        SkillPracticeModeDataGroup(),
        ShopDataGroup(),
        ShopDataGroup(),
        ConfigEquipmentPropertyBag(),
        DropItemDataGroup(),
        MonsterRandomAmountDataGroup(),
        RandomBattleGroupDataGroup(),
        TransportDataGroup(),
        CharacterExpDataGroup(),
        InstanceDataGroup(),
        InjectSoulDataGroup(),
        SpaceTimeBattleDataGroup(),
        EquipmentStrengthDataGroup(),
        EquipmentXilianDataGroup(),
        DailyQuestCategoryDataGroup(),
        DailyQuestLibDataGroup(),
        DailyQuestRewardDataGroup(),
        DailyLimitCooldownDataGroup(),
        DailyLimitCooldownClearDataGroup(),
        DailyLimitPurchaseDataGroup(),
        DailyLimitCountDataGroup(),
        InstanceNPCDataGroup(),
        
        BuyChallengeTimesCostDataGroup(),
        BuyClearCDCostDataGroup(),
        ChallengeBonusDataGroup(),
        ChallengeContWinTitleDataGroup(),
        ChallengeRankTitleDataGroup(),
        TreasureBoxDataGroup(),
        YinglingHiringSlotDataGroup(),
        YinglingHiringConfigDataGroup(),
        YinglingSlotDataGroup(),
        YinglingLingliConvertDataGroup(),
        YinglingLingliSummonDataGroup(),
        ItemGiftDataGroup(),
        ItemYinglingDataGroup(),
        RandNameDataGroup(),
        ResourceDataGroup(),
        DefaultHideNpcDataGroup(),
        QuestHideNpcDataGroup(),
        VipBonusDataGroup(),
        GiftPackDataGroup(),
        GiftDailyDataGroup(),
        OnlineTimeBonusDataGroup(),
        TeamFightExpFactorDataGroup(),
        AutoSkipFightTimeLimitDataGroup(),
        FightCoolDownLimitDataGroup(),
        PayByTypeDataGroup(),
        InstanceTreasureDataGroup(),
        ]

# 二级 instance
classgroup = [
        LevelExperience,
        # multi-line
        PlayerInitData,
        CharacterProGrowRate,
        YinglingProGrownRate,
        PlayerAttrTransition,
        # repeated fields
        YinglingInitData,
        CreatureInitData,
        PropsData,
        EquipmentData,
        StoneData,
        MagicItemData,
        #NPCData,
        BattleNPCData,
        BattleGroupData,
        SkillData,
        SkillBookData,
        SkillPracticeModeData,
        ShopData,
        ShopData,
        ConfigEquipmentProperty,
        DropItemData,
        MonsterRandomAmountData,
        RandomBattleGroupData,
        TransportData,
        CharacterExpData,
        InstanceData,
        InjectSoulData,
        SpaceTimeBattleData,
        EquipmentStrengthData,
        EquipmentXilianData,
        DailyQuestCategoryData,
        DailyQuestLibData,
        DailyQuestRewardData,
        DailyLimitCooldownData,
        DailyLimitCooldownClearData,
        DailyLimitPurchaseData,
        DailyLimitCountData,
        InstanceNPCData,
        BuyChallengeTimesCostData,
        BuyClearCDCostData,
        ChallengeBonusData,
        ChallengeContWinTitleData,
        ChallengeRankTitleData,
        TreasureBoxData,
        YinglingHiringSlotData,
        YinglingHiringConfigData,
        YinglingSlotData,
        YinglingLingliConvertData,
        YinglingLingliSummonData,
        ItemGiftData,
        ItemYinglingData,
        RandNameData,
        ResourceData,
        DefaultHideNpcData,
        QuestHideNpcData,
        VipBonusData,
        GiftPackData,
        GiftDailyData,
        OnlineTimeBonusData,
        TeamFightExpFactorData,
        AutoSkipFightTimeLimitData,
        FightCoolDownLimitData,
        PayByTypeData,
        InstanceTreasureData(),
        ]

assert len(csvfiles) == len(binfiles)
assert len(csvfiles) == len(fields)
assert len(csvfiles) == len(classgroup)
assert len(csvfiles) == len(groupInst)

# parse the first 3-lines : fieldname, description, type
def parseCsvHeader(csvreader):
    row = 0
    csvfields = []
    for line in csvreader:
        if row == 0: # read field names into a list
            for k in xrange(len(line)):
                if k == 0:
                    # utf-8 coding, need special handle
                    # change to ansi 
                    line[k] = line[k][0:] 
                csvfields.append(line[k])
                print csvfields[k],
            row = row + 1
            print
            continue
        # second line is description , ignore
        # third line is type, ignore 
        elif row == 1: 
            row = row + 1
            continue
        elif row == 2:
            break
    return csvfields
    
def do_group_parse(i, reader, ginst, csvfields):
    # for each field in ginst
    #inst = ginst.fieldsname.add()
    #do_inst_parse(i, reader, inst)
    if csvfiletype[i] == 2 and ginst != "":
        cols = groupfields[i]
        for j in range(len(cols)):
            fieldname = cols[j].name

            # find the corresponding instance
            if hasattr(ginst, fieldname):
                inst = getattr(ginst, fieldname)
                #print "getattr(ginst, %s)" % (fieldname) 
            do_inst_parse(i, reader, inst, csvfields)

    # for repeated fields in group
    elif csvfiletype[i] == 3 and ginst != "":
        gfield = groupfields[i]
        repeatfield = gfield[0].name
        #print "gfield name :", repeatfield

        for line in reader:
            lines = []
            lines.insert(0, line)
            if len(lines[0]) <= 1: # last line 
                break

            inst = eval("ginst.%s.add()"%(repeatfield))
            #print "do repeated field %s parse" % (repeatfield)
            do_inst_parse(i, lines, inst, csvfields)
    
    else:
        print "\n-- !!! unknow csv file types."
       
    

def do_inst_parse(i, reader, inst, csvfields):
    
    cols = fields[i]
    colnames = [] # the name define in protobuff
    for j in range(len(cols)):
        colname = cols[j].name
        colnames.append( colname )
    
    row = 0
    # for each line in csv file
    for line in reader:

        # some field may not in the proto file
        #print "line len(%d), colnames len(%d)" % (len(line), len(colnames))
        #print "line : " , line
        #print "colnames: ", colnames
        assert len(line) >= len(colnames)
                
        # for each field in the columns
        fieldname = ""
        for k in xrange(len(line)): 
            fieldname = csvfields[k]
            #print "csv field: [attr: %s], [csvfields: %s]" % (fieldname, csvfields[k])
            if hasattr(inst, fieldname):
                # find the index in proto
                at = -1
                for index in xrange(len(colnames)):
                    if colnames[index] == fieldname:
                        at = index
                assert at >= 0   # hasattr() already return true
                #print "setattr %s = %s" % (fieldname, (line[k]))
                ss = u'unicode_test'
                #print cols[at].type
                #print type(line[k])
                #print type(getattr(inst, fieldname))
                if cols[at].type == 2: # python float type
                    setattr(inst, fieldname, float(line[k]))
                elif cols[at].type == 5: # python int type
                    setattr(inst, fieldname, int(float(line[k])))
                #elif type(getattr(inst, fieldname)) == str:
                elif cols[at].type == 9: # python string type
                        tmp_str = line[k]
                        if type(getattr(inst, fieldname)) == type(ss):
                            setattr(inst, fieldname, tmp_str.decode('gbk'))
                            #print tmp_str.decode('gbk')
                        else:
                            setattr(inst, fieldname, tmp_str)
        row = row + 1
        #print "row: ", row 
        break # each line is a single instance
    
# Parse each file in csvfiles
def parse_all_file():
    filecount = len(csvfiles)
    for i in xrange(filecount):
        print "\nparse %s " % csvfiles[i]
        f = open((csvbasedir + "/" + csvfiles[i]), "rb")
        reader = csv.reader(f)
        writer = open(binbasedir + "/" + binfiles[i], "wb")
    
        ginst = groupInst[i]
    
        csvfields = []
        csvfields = parseCsvHeader(reader)
    
        if csvfiletype[i] > 1 and ginst != "":
            do_group_parse(i, reader, ginst, csvfields)
            msg = ginst.SerializeToString()    
        else :
            inst = classgroup[i]()
            do_inst_parse(i, reader, inst, csvfields)
            msg = inst.SerializeToString()
        
        writer.write(msg)
        writer.close()
        f.close()
    
    dumpcsv(filecount)
    #print "\npaser csv files finished,Please goto ./streams to check"


# from protobuff binary stream dump to csv files
def dumpcsv(filecount):
    basedir = "dump.csv"
    #global filecount
    for i in xrange(filecount):
        orig_csv = open((csvbasedir + "/" + csvfiles[i]), "rb")
        reader = csv.reader(orig_csv) 
        #print "\nopen original csv file: %s for read field names" % (csvbasedir + "/" + csvfiles[i])
        writer = csv.writer( open(basedir + "/" + csvfiles[i], "wb") )
        #print "open dump.csv file: %s for write" % (basedir + "/" + csvfiles[i])
        f = open( binbasedir + "/" + binfiles[i], "rb")
        
        # write csv fieldname line -- the first line
        csvfields = []
        csvfields = parseCsvHeader(reader)
        writer.writerow(csvfields)
        
        ginst = groupInst[i]
        
        if csvfiletype[i] > 1 and ginst != "":
            ginst.ParseFromString(f.read())
            if csvfiletype[i] == 2:
                do_group_dump(i, writer, ginst, csvfields)
            elif csvfiletype[i] == 3:
                do_repeated_dump(i, writer, ginst, csvfields)
            else:
                print "!!! invalid csv file type !!!"
        else:
            inst = classgroup[i]()
            inst.ParseFromString(f.read())
            do_inst_dump(i, writer, inst, csvfields)
            
        f.close()
        orig_csv.close()
    
def do_group_dump(i, writer, ginst, csvfields):
    # for each field inst in ginst
    # parse inst's attr and write
    # it to the csv files
    valuelist = ginst.ListFields()

    cols = groupfields[i]
    for j in range(len(cols)):
        fieldname = cols[j].name

        # find the corresponding instance
        try:
            if ginst.HasField(fieldname):
                #print "\nhas field ", fieldname
                for fd, value in valuelist:
                    if fd.name == fieldname:
                        inst = value
                        do_inst_dump(i, writer, inst, csvfields)
        except:
            print "!!!! field: %s not set" % fieldname
                
def do_repeated_dump(i, writer, ginst, csvfields):
    
    # for each line in ginst, add it to the csv files 
    gfield = groupfields[i]
    repeatfield = gfield[0].name
    print "gfield name :", repeatfield

    insts = eval("ginst.%s" % (repeatfield))
    for repeated in insts:
        do_inst_dump(i, writer, repeated, csvfields)
    
        
def do_inst_dump(i, writer, inst, csvfields):
    # for each field in csv, find the value in protobuff
    # if it's can't find, set it to ""
    valuelist = inst.ListFields()
    #print valuelist

    line = []
    for i in xrange(len(csvfields)):
        try:
            if inst.HasField(csvfields[i]):
                for fd, value in valuelist:
                    if fd.name == csvfields[i]:
                        #print "get %s value: %s" % (fd.name, str(value))
                        line.append(value)
        except ValueError:
            line.append("")
    writer.writerow(line)
    
if __name__ == "__main__":
    parse_all_file()
