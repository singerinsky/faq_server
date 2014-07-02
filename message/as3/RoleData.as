package  {
	import com.netease.protobuf.*;
	use namespace com.netease.protobuf.used_by_generated_code;
	import com.netease.protobuf.fieldDescriptors.*;
	import flash.utils.Endian;
	import flash.utils.IDataInput;
	import flash.utils.IDataOutput;
	import flash.utils.IExternalizable;
	import flash.errors.IOError;
	import db_role_info;
	// @@protoc_insertion_point(imports)

	// @@protoc_insertion_point(class_metadata)
	public dynamic final class RoleData extends com.netease.protobuf.Message {
		/**
		 *  @private
		 */
		public static const ROLE_DATA:FieldDescriptor$TYPE_MESSAGE = new FieldDescriptor$TYPE_MESSAGE("RoleData.role_data", "roleData", (1 << 3) | com.netease.protobuf.WireType.LENGTH_DELIMITED, db_role_info);

		public var roleData:db_role_info;

		/**
		 *  @private
		 */
		override used_by_generated_code final function writeToBuffer(output:com.netease.protobuf.WritingBuffer):void {
			com.netease.protobuf.WriteUtils.writeTag(output, com.netease.protobuf.WireType.LENGTH_DELIMITED, 1);
			com.netease.protobuf.WriteUtils.write$TYPE_MESSAGE(output, this.roleData);
			for (var fieldKey:* in this) {
				super.writeUnknown(output, fieldKey);
			}
		}

		/**
		 *  @private
		 */
		override used_by_generated_code final function readFromSlice(input:flash.utils.IDataInput, bytesAfterSlice:uint):void {
			var role_data$count:uint = 0;
			while (input.bytesAvailable > bytesAfterSlice) {
				var tag:uint = com.netease.protobuf.ReadUtils.read$TYPE_UINT32(input);
				switch (tag >> 3) {
				case 1:
					if (role_data$count != 0) {
						throw new flash.errors.IOError('Bad data format: RoleData.roleData cannot be set twice.');
					}
					++role_data$count;
					this.roleData = new db_role_info();
					com.netease.protobuf.ReadUtils.read$TYPE_MESSAGE(input, this.roleData);
					break;
				default:
					super.readUnknown(input, tag);
					break;
				}
			}
		}

	}
}
