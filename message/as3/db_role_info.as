package  {
	import com.netease.protobuf.*;
	use namespace com.netease.protobuf.used_by_generated_code;
	import com.netease.protobuf.fieldDescriptors.*;
	import flash.utils.Endian;
	import flash.utils.IDataInput;
	import flash.utils.IDataOutput;
	import flash.utils.IExternalizable;
	import flash.errors.IOError;
	// @@protoc_insertion_point(imports)

	// @@protoc_insertion_point(class_metadata)
	public dynamic final class db_role_info extends com.netease.protobuf.Message {
		/**
		 *  @private
		 */
		public static const ROLE_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.role_id", "roleId", (1 << 3) | com.netease.protobuf.WireType.VARINT);

		public var roleId:int;

		/**
		 *  @private
		 */
		public static const UID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.uid", "uid", (2 << 3) | com.netease.protobuf.WireType.VARINT);

		public var uid:int;

		/**
		 *  @private
		 */
		public static const TID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.tid", "tid", (3 << 3) | com.netease.protobuf.WireType.VARINT);

		public var tid:int;

		/**
		 *  @private
		 */
		public static const NAME:FieldDescriptor$TYPE_STRING = new FieldDescriptor$TYPE_STRING("db_role_info.name", "name", (4 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED);

		public var name:String;

		/**
		 *  @private
		 */
		public static const GENDER:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.gender", "gender", (5 << 3) | com.netease.protobuf.WireType.VARINT);

		public var gender:int;

		/**
		 *  @private
		 */
		public static const JOB_TYPE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.job_type", "jobType", (6 << 3) | com.netease.protobuf.WireType.VARINT);

		public var jobType:int;

		/**
		 *  @private
		 */
		public static const ROLE_LEVEL:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.role_level", "roleLevel", (7 << 3) | com.netease.protobuf.WireType.VARINT);

		public var roleLevel:int;

		/**
		 *  @private
		 */
		public static const ROLE_EXP:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.role_exp", "roleExp", (8 << 3) | com.netease.protobuf.WireType.VARINT);

		public var roleExp:int;

		/**
		 *  @private
		 */
		public static const COSTUME_TID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.costume_tid", "costumeTid", (9 << 3) | com.netease.protobuf.WireType.VARINT);

		public var costumeTid:int;

		/**
		 *  @private
		 */
		public static const TITLE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.title", "title", (10 << 3) | com.netease.protobuf.WireType.VARINT);

		public var title:int;

		/**
		 *  @private
		 */
		public static const COIN:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.coin", "coin", (11 << 3) | com.netease.protobuf.WireType.VARINT);

		public var coin:int;

		/**
		 *  @private
		 */
		public static const COUPON:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.coupon", "coupon", (12 << 3) | com.netease.protobuf.WireType.VARINT);

		public var coupon:int;

		/**
		 *  @private
		 */
		public static const DIAMOND:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.diamond", "diamond", (13 << 3) | com.netease.protobuf.WireType.VARINT);

		public var diamond:int;

		/**
		 *  @private
		 */
		public static const VIP_END_TS:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.vip_end_ts", "vipEndTs", (14 << 3) | com.netease.protobuf.WireType.VARINT);

		public var vipEndTs:int;

		/**
		 *  @private
		 */
		public static const VIP_LEVEL:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.vip_level", "vipLevel", (15 << 3) | com.netease.protobuf.WireType.VARINT);

		public var vipLevel:int;

		/**
		 *  @private
		 */
		public static const MAP_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.map_id", "mapId", (16 << 3) | com.netease.protobuf.WireType.VARINT);

		public var mapId:int;

		/**
		 *  @private
		 */
		public static const MAP_X:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.map_x", "mapX", (17 << 3) | com.netease.protobuf.WireType.VARINT);

		public var mapX:int;

		/**
		 *  @private
		 */
		public static const MAP_Y:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.map_y", "mapY", (18 << 3) | com.netease.protobuf.WireType.VARINT);

		public var mapY:int;

		/**
		 *  @private
		 */
		public static const LAST_MAP_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.last_map_id", "lastMapId", (19 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lastMapId:int;

		/**
		 *  @private
		 */
		public static const LAST_MAP_X:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.last_map_x", "lastMapX", (20 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lastMapX:int;

		/**
		 *  @private
		 */
		public static const LAST_MAP_Y:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.last_map_y", "lastMapY", (21 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lastMapY:int;

		/**
		 *  @private
		 */
		public static const FLAG:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.flag", "flag", (22 << 3) | com.netease.protobuf.WireType.VARINT);

		public var flag:int;

		/**
		 *  @private
		 */
		public static const STATUS:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.status", "status", (23 << 3) | com.netease.protobuf.WireType.VARINT);

		public var status:int;

		/**
		 *  @private
		 */
		public static const SERVER_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.server_id", "serverId", (24 << 3) | com.netease.protobuf.WireType.VARINT);

		public var serverId:int;

		/**
		 *  @private
		 */
		public static const CREATE_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.create_time", "createTime", (25 << 3) | com.netease.protobuf.WireType.VARINT);

		public var createTime:int;

		/**
		 *  @private
		 */
		public static const TEAM_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.team_id", "teamId", (26 << 3) | com.netease.protobuf.WireType.VARINT);

		public var teamId:int;

		/**
		 *  @private
		 */
		public static const TEAM_CREATE_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.team_create_time", "teamCreateTime", (27 << 3) | com.netease.protobuf.WireType.VARINT);

		public var teamCreateTime:int;

		/**
		 *  @private
		 */
		public static const BAG_SIZE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.bag_size", "bagSize", (28 << 3) | com.netease.protobuf.WireType.VARINT);

		public var bagSize:int;

		/**
		 *  @private
		 */
		public static const DEPOT_SIZE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.depot_size", "depotSize", (29 << 3) | com.netease.protobuf.WireType.VARINT);

		public var depotSize:int;

		/**
		 *  @private
		 */
		public static const BUDDY_SIZE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.buddy_size", "buddySize", (30 << 3) | com.netease.protobuf.WireType.VARINT);

		public var buddySize:int;

		/**
		 *  @private
		 */
		public static const LINEUP_SIZE:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.lineup_size", "lineupSize", (31 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lineupSize:int;

		/**
		 *  @private
		 */
		public static const DEFAULT_LINEUP_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.default_lineup_id", "defaultLineupId", (32 << 3) | com.netease.protobuf.WireType.VARINT);

		public var defaultLineupId:int;

		/**
		 *  @private
		 */
		public static const LINEUP_CAPACITY:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.lineup_capacity", "lineupCapacity", (33 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lineupCapacity:int;

		/**
		 *  @private
		 */
		public static const LOGIN_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.login_time", "loginTime", (34 << 3) | com.netease.protobuf.WireType.VARINT);

		public var loginTime:int;

		/**
		 *  @private
		 */
		public static const LAST_LOGOFF_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.last_logoff_time", "lastLogoffTime", (35 << 3) | com.netease.protobuf.WireType.VARINT);

		public var lastLogoffTime:int;

		/**
		 *  @private
		 */
		public static const LOGIN_IP:FieldDescriptor$TYPE_STRING = new FieldDescriptor$TYPE_STRING("db_role_info.login_ip", "loginIp", (36 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED);

		public var loginIp:String;

		/**
		 *  @private
		 */
		public static const INSTANCE_COUNT:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.instance_count", "instanceCount", (37 << 3) | com.netease.protobuf.WireType.VARINT);

		public var instanceCount:int;

		/**
		 *  @private
		 */
		public static const INSTANCE_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.instance_time", "instanceTime", (38 << 3) | com.netease.protobuf.WireType.VARINT);

		public var instanceTime:int;

		/**
		 *  @private
		 */
		public static const GUILD_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.guild_id", "guildId", (39 << 3) | com.netease.protobuf.WireType.VARINT);

		public var guildId:int;

		/**
		 *  @private
		 */
		public static const GUILD_TIME:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.guild_time", "guildTime", (40 << 3) | com.netease.protobuf.WireType.VARINT);

		public var guildTime:int;

		/**
		 *  @private
		 */
		public static const GUILD_NAME:FieldDescriptor$TYPE_STRING = new FieldDescriptor$TYPE_STRING("db_role_info.guild_name", "guildName", (41 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED);

		public var guildName:String;

		/**
		 *  @private
		 */
		public static const PHY_STRENGTH:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.phy_strength", "phyStrength", (42 << 3) | com.netease.protobuf.WireType.VARINT);

		public var phyStrength:int;

		/**
		 *  @private
		 */
		public static const EXTRA_PHY_STRENGTH:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.extra_phy_strength", "extraPhyStrength", (43 << 3) | com.netease.protobuf.WireType.VARINT);

		public var extraPhyStrength:int;

		/**
		 *  @private
		 */
		public static const TIME_TO_RECOVER_PHY_STRENGTH:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.time_to_recover_phy_strength", "timeToRecoverPhyStrength", (44 << 3) | com.netease.protobuf.WireType.VARINT);

		public var timeToRecoverPhyStrength:int;

		/**
		 *  @private
		 */
		public static const TIME_TO_RECOVER_EXTRA_PHY_STRENGTH:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.time_to_recover_extra_phy_strength", "timeToRecoverExtraPhyStrength", (45 << 3) | com.netease.protobuf.WireType.VARINT);

		public var timeToRecoverExtraPhyStrength:int;

		/**
		 *  @private
		 */
		public static const RENOWN:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("db_role_info.renown", "renown", (46 << 3) | com.netease.protobuf.WireType.VARINT);

		public var renown:int;

		/**
		 *  @private
		 */
		override used_by_generated_code final function writeToBuffer(output:com.netease.protobuf.WritingBuffer):void {
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 1);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.roleId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 2);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.uid);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 3);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.tid);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 4);
			com.netease.protobuf.WriteUtils.write$TYPE_STRING(output, this.name);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 5);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.gender);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 6);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.jobType);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 7);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.roleLevel);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 8);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.roleExp);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 9);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.costumeTid);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 10);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.title);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 11);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.coin);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 12);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.coupon);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 13);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.diamond);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 14);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.vipEndTs);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 15);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.vipLevel);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 16);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.mapId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 17);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.mapX);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 18);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.mapY);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 19);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lastMapId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 20);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lastMapX);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 21);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lastMapY);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 22);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.flag);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 23);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.status);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 24);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.serverId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 25);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.createTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 26);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.teamId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 27);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.teamCreateTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 28);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.bagSize);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 29);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.depotSize);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 30);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.buddySize);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 31);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lineupSize);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 32);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.defaultLineupId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 33);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lineupCapacity);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 34);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.loginTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 35);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.lastLogoffTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 36);
			com.netease.protobuf.WriteUtils.write$TYPE_STRING(output, this.loginIp);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 37);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.instanceCount);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 38);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.instanceTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 39);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.guildId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 40);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.guildTime);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 41);
			com.netease.protobuf.WriteUtils.write$TYPE_STRING(output, this.guildName);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 42);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.phyStrength);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 43);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.extraPhyStrength);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 44);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.timeToRecoverPhyStrength);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 45);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.timeToRecoverExtraPhyStrength);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 46);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.renown);
			for (var fieldKey:* in this) {
				super.writeUnknown(output, fieldKey);
			}
		}

		/**
		 *  @private
		 */
		override used_by_generated_code final function readFromSlice(input:flash.utils.IDataInput, bytesAfterSlice:uint):void {
			var role_id$count:uint = 0;
			var uid$count:uint = 0;
			var tid$count:uint = 0;
			var name$count:uint = 0;
			var gender$count:uint = 0;
			var job_type$count:uint = 0;
			var role_level$count:uint = 0;
			var role_exp$count:uint = 0;
			var costume_tid$count:uint = 0;
			var title$count:uint = 0;
			var coin$count:uint = 0;
			var coupon$count:uint = 0;
			var diamond$count:uint = 0;
			var vip_end_ts$count:uint = 0;
			var vip_level$count:uint = 0;
			var map_id$count:uint = 0;
			var map_x$count:uint = 0;
			var map_y$count:uint = 0;
			var last_map_id$count:uint = 0;
			var last_map_x$count:uint = 0;
			var last_map_y$count:uint = 0;
			var flag$count:uint = 0;
			var status$count:uint = 0;
			var server_id$count:uint = 0;
			var create_time$count:uint = 0;
			var team_id$count:uint = 0;
			var team_create_time$count:uint = 0;
			var bag_size$count:uint = 0;
			var depot_size$count:uint = 0;
			var buddy_size$count:uint = 0;
			var lineup_size$count:uint = 0;
			var default_lineup_id$count:uint = 0;
			var lineup_capacity$count:uint = 0;
			var login_time$count:uint = 0;
			var last_logoff_time$count:uint = 0;
			var login_ip$count:uint = 0;
			var instance_count$count:uint = 0;
			var instance_time$count:uint = 0;
			var guild_id$count:uint = 0;
			var guild_time$count:uint = 0;
			var guild_name$count:uint = 0;
			var phy_strength$count:uint = 0;
			var extra_phy_strength$count:uint = 0;
			var time_to_recover_phy_strength$count:uint = 0;
			var time_to_recover_extra_phy_strength$count:uint = 0;
			var renown$count:uint = 0;
			while (input.bytesAvailable > bytesAfterSlice) {
				var tag:uint = com.netease.protobuf.ReadUtils.read$TYPE_UINT32(input);
				switch (tag >> 3) {
				case 1:
					if (role_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.roleId cannot be set twice.');
					}
					++role_id$count;
					this.roleId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 2:
					if (uid$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.uid cannot be set twice.');
					}
					++uid$count;
					this.uid = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 3:
					if (tid$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.tid cannot be set twice.');
					}
					++tid$count;
					this.tid = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 4:
					if (name$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.name cannot be set twice.');
					}
					++name$count;
					this.name = com.netease.protobuf.ReadUtils.read$TYPE_STRING(input);
					break;
				case 5:
					if (gender$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.gender cannot be set twice.');
					}
					++gender$count;
					this.gender = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 6:
					if (job_type$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.jobType cannot be set twice.');
					}
					++job_type$count;
					this.jobType = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 7:
					if (role_level$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.roleLevel cannot be set twice.');
					}
					++role_level$count;
					this.roleLevel = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 8:
					if (role_exp$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.roleExp cannot be set twice.');
					}
					++role_exp$count;
					this.roleExp = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 9:
					if (costume_tid$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.costumeTid cannot be set twice.');
					}
					++costume_tid$count;
					this.costumeTid = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 10:
					if (title$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.title cannot be set twice.');
					}
					++title$count;
					this.title = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 11:
					if (coin$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.coin cannot be set twice.');
					}
					++coin$count;
					this.coin = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 12:
					if (coupon$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.coupon cannot be set twice.');
					}
					++coupon$count;
					this.coupon = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 13:
					if (diamond$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.diamond cannot be set twice.');
					}
					++diamond$count;
					this.diamond = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 14:
					if (vip_end_ts$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.vipEndTs cannot be set twice.');
					}
					++vip_end_ts$count;
					this.vipEndTs = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 15:
					if (vip_level$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.vipLevel cannot be set twice.');
					}
					++vip_level$count;
					this.vipLevel = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 16:
					if (map_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.mapId cannot be set twice.');
					}
					++map_id$count;
					this.mapId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 17:
					if (map_x$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.mapX cannot be set twice.');
					}
					++map_x$count;
					this.mapX = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 18:
					if (map_y$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.mapY cannot be set twice.');
					}
					++map_y$count;
					this.mapY = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 19:
					if (last_map_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lastMapId cannot be set twice.');
					}
					++last_map_id$count;
					this.lastMapId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 20:
					if (last_map_x$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lastMapX cannot be set twice.');
					}
					++last_map_x$count;
					this.lastMapX = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 21:
					if (last_map_y$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lastMapY cannot be set twice.');
					}
					++last_map_y$count;
					this.lastMapY = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 22:
					if (flag$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.flag cannot be set twice.');
					}
					++flag$count;
					this.flag = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 23:
					if (status$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.status cannot be set twice.');
					}
					++status$count;
					this.status = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 24:
					if (server_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.serverId cannot be set twice.');
					}
					++server_id$count;
					this.serverId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 25:
					if (create_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.createTime cannot be set twice.');
					}
					++create_time$count;
					this.createTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 26:
					if (team_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.teamId cannot be set twice.');
					}
					++team_id$count;
					this.teamId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 27:
					if (team_create_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.teamCreateTime cannot be set twice.');
					}
					++team_create_time$count;
					this.teamCreateTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 28:
					if (bag_size$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.bagSize cannot be set twice.');
					}
					++bag_size$count;
					this.bagSize = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 29:
					if (depot_size$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.depotSize cannot be set twice.');
					}
					++depot_size$count;
					this.depotSize = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 30:
					if (buddy_size$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.buddySize cannot be set twice.');
					}
					++buddy_size$count;
					this.buddySize = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 31:
					if (lineup_size$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lineupSize cannot be set twice.');
					}
					++lineup_size$count;
					this.lineupSize = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 32:
					if (default_lineup_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.defaultLineupId cannot be set twice.');
					}
					++default_lineup_id$count;
					this.defaultLineupId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 33:
					if (lineup_capacity$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lineupCapacity cannot be set twice.');
					}
					++lineup_capacity$count;
					this.lineupCapacity = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 34:
					if (login_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.loginTime cannot be set twice.');
					}
					++login_time$count;
					this.loginTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 35:
					if (last_logoff_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.lastLogoffTime cannot be set twice.');
					}
					++last_logoff_time$count;
					this.lastLogoffTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 36:
					if (login_ip$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.loginIp cannot be set twice.');
					}
					++login_ip$count;
					this.loginIp = com.netease.protobuf.ReadUtils.read$TYPE_STRING(input);
					break;
				case 37:
					if (instance_count$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.instanceCount cannot be set twice.');
					}
					++instance_count$count;
					this.instanceCount = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 38:
					if (instance_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.instanceTime cannot be set twice.');
					}
					++instance_time$count;
					this.instanceTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 39:
					if (guild_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.guildId cannot be set twice.');
					}
					++guild_id$count;
					this.guildId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 40:
					if (guild_time$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.guildTime cannot be set twice.');
					}
					++guild_time$count;
					this.guildTime = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 41:
					if (guild_name$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.guildName cannot be set twice.');
					}
					++guild_name$count;
					this.guildName = com.netease.protobuf.ReadUtils.read$TYPE_STRING(input);
					break;
				case 42:
					if (phy_strength$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.phyStrength cannot be set twice.');
					}
					++phy_strength$count;
					this.phyStrength = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 43:
					if (extra_phy_strength$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.extraPhyStrength cannot be set twice.');
					}
					++extra_phy_strength$count;
					this.extraPhyStrength = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 44:
					if (time_to_recover_phy_strength$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.timeToRecoverPhyStrength cannot be set twice.');
					}
					++time_to_recover_phy_strength$count;
					this.timeToRecoverPhyStrength = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 45:
					if (time_to_recover_extra_phy_strength$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.timeToRecoverExtraPhyStrength cannot be set twice.');
					}
					++time_to_recover_extra_phy_strength$count;
					this.timeToRecoverExtraPhyStrength = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 46:
					if (renown$count != 0) {
						throw new flash.errors.IOError('Bad data format: db_role_info.renown cannot be set twice.');
					}
					++renown$count;
					this.renown = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				default:
					super.readUnknown(input, tag);
					break;
				}
			}
		}

	}
}
