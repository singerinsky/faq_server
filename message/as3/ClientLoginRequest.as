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
	public dynamic final class ClientLoginRequest extends com.netease.protobuf.Message {
		/**
		 *  @private
		 */
		public static const PLAYER_ID:FieldDescriptor$TYPE_INT32 = new FieldDescriptor$TYPE_INT32("ClientLoginRequest.player_id", "playerId", (1 << 3) | com.netease.protobuf.WireType.VARINT);

		public var playerId:int;

		/**
		 *  @private
		 */
		public static const PLAYER_PWD:FieldDescriptor$TYPE_STRING = new FieldDescriptor$TYPE_STRING("ClientLoginRequest.player_pwd", "playerPwd", (2 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED);

		public var playerPwd:String;

		/**
		 *  @private
		 */
		public static const MD5_CODE:FieldDescriptor$TYPE_STRING = new FieldDescriptor$TYPE_STRING("ClientLoginRequest.md5_code", "md5Code", (3 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED);

		public var md5Code:String;

		/**
		 *  @private
		 */
		override used_by_generated_code final function writeToBuffer(output:com.netease.protobuf.WritingBuffer):void {
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.VARINT, 1);
			com.netease.protobuf.WriteUtils.write$TYPE_INT32(output, this.playerId);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 2);
			com.netease.protobuf.WriteUtils.write$TYPE_STRING(output, this.playerPwd);
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 3);
			com.netease.protobuf.WriteUtils.write$TYPE_STRING(output, this.md5Code);
			for (var fieldKey:* in this) {
				super.writeUnknown(output, fieldKey);
			}
		}

		/**
		 *  @private
		 */
		override used_by_generated_code final function readFromSlice(input:flash.utils.IDataInput, bytesAfterSlice:uint):void {
			var player_id$count:uint = 0;
			var player_pwd$count:uint = 0;
			var md5_code$count:uint = 0;
			while (input.bytesAvailable > bytesAfterSlice) {
				var tag:uint = com.netease.protobuf.ReadUtils.read$TYPE_UINT32(input);
				switch (tag >> 3) {
				case 1:
					if (player_id$count != 0) {
						throw new flash.errors.IOError('Bad data format: ClientLoginRequest.playerId cannot be set twice.');
					}
					++player_id$count;
					this.playerId = com.netease.protobuf.ReadUtils.read$TYPE_INT32(input);
					break;
				case 2:
					if (player_pwd$count != 0) {
						throw new flash.errors.IOError('Bad data format: ClientLoginRequest.playerPwd cannot be set twice.');
					}
					++player_pwd$count;
					this.playerPwd = com.netease.protobuf.ReadUtils.read$TYPE_STRING(input);
					break;
				case 3:
					if (md5_code$count != 0) {
						throw new flash.errors.IOError('Bad data format: ClientLoginRequest.md5Code cannot be set twice.');
					}
					++md5_code$count;
					this.md5Code = com.netease.protobuf.ReadUtils.read$TYPE_STRING(input);
					break;
				default:
					super.readUnknown(input, tag);
					break;
				}
			}
		}

	}
}
