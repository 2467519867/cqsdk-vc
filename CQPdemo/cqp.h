/*
* CoolQ SDK for VC++ 
* Api Version 9.6
* Written by Coxxs & Thanks for the help of orzFly
*/
#pragma once

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

#ifndef CQAPI
#define CQAPI(ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall
#endif

#define CQEVENT(ReturnType, Name, Size) __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size))\
 extern "C" __declspec(dllexport) ReturnType __stdcall Name

typedef int32_t CQBOOL;

#define EVENT_IGNORE 0        //事件_忽略
#define EVENT_BLOCK 1         //事件_拦截

#define REQUEST_ALLOW 1       //请求_通过
#define REQUEST_DENY 2        //请求_拒绝

#define REQUEST_GROUPADD 1    //请求_群添加
#define REQUEST_GROUPINVITE 2 //请求_群邀请

#define CQLOG_DEBUG 0           //调试 灰色
#define CQLOG_INFO 10           //信息 黑色
#define CQLOG_INFOSUCCESS 11    //信息(成功) 紫色
#define CQLOG_INFORECV 12       //信息(接收) 蓝色
#define CQLOG_INFOSEND 13       //信息(发送) 绿色
#define CQLOG_WARNING 20        //警告 橙色
#define CQLOG_ERROR 30          //错误 红色
#define CQLOG_FATAL 40          //致命错误 深红

/*
* 发送私聊消息, 整数型, , Auth=106
* 参数 QQID, 长整数型, , 目标QQ
* 参数 msg, 文本型, , 消息内容
*/
CQAPI(int32_t) CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);
/*
* 发送群消息, 整数型, , Auth=101
* 参数 groupid, 长整数型, , 目标群
* 参数 msg, 文本型, , 消息内容
*/
CQAPI(int32_t) CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);
/*
* 发送讨论组消息, 整数型, , Auth=103
* 参数 discussid, 长整数型, , 目标讨论组
* 参数 msg, 文本型, , 消息内容
*/
CQAPI(int32_t) CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);
/*
* 发送赞, 整数型, , Auth=110 发送手机赞
* 参数 QQID, 长整数型, , 目标QQ
* 参数 number, 整数型, 可空, 赞的次数，最多10次（留空为1次）
*/
CQAPI(int32_t) CQ_sendLike(int32_t AuthCode, int64_t QQID,int32_t number);
/*
* 置群员移除, 整数型, , Auth=120
* 参数 groupid, 长整数型, , 目标群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 rejectaddrequest, 逻辑型, 可空, 如果为true，则“不再接收此人加群申请”，请慎用。留空为false
*/
CQAPI(int32_t) CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);
/*
* 置群员禁言, 整数型, , Auth=121
* 参数 groupid, 长整数型, , 目标群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 duration, 长整数型, , 禁言的时间，单位为秒。如果要解禁，这里填写0
*/
CQAPI(int32_t) CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);
/*
* 置群管理员, 整数型, , Auth=122
* 参数 groupid, 长整数型, , 目标群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 setadmin, 逻辑型, , true/设置管理员 false/取消管理员
*/
CQAPI(int32_t) CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL setadmin);
/*
* 置全群禁言, 整数型, , Auth=123
* 参数 groupid, 长整数型, , 目标群
* 参数 enableban, 逻辑型, , true/开启 false/关闭
*/
CQAPI(int32_t) CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQBOOL enableban);
/*
* 置匿名群员禁言, 整数型, , Auth=124
* 参数 groupid, 长整数型, , 目标群
* 参数 anomymous, 文本型, , 群消息事件收到的“匿名”参数
* 参数 duration, 长整数型, , 禁言的时间，单位为秒。不支持解禁
*/
CQAPI(int32_t) CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);
/*
* 置群匿名置, 整数型, , Auth=125
* 参数 groupid, 长整数型 目标群
* 参数 enableanomymous, 逻辑型 
*/
CQAPI(int32_t) CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQBOOL enableanomymous);
/*
* 置群成员名片, 整数型, , Auth=126
* 参数 groupid, 长整数型, , 目标群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 newcard, 文本型, ,新名片_昵称
*/
CQAPI(int32_t) CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);
/*
* 置群退出, 整数型, , Auth=127 慎用,此接口需要严格授权
* 参数 groupid, 长整数型, , 目标群
* 参数 isdismiss, 逻辑型, 可空, 默认为假 true/解散本群(群主) false/退出本群(管理、群成员)
*/
CQAPI(int32_t) CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQBOOL isdismiss);
/*
* 置群成员专属头衔, 整数型, , Auth=128 需群主权限
* 参数 groupid, 长整数型, , 目标群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 newspecialtitle, 文本型, , 如果要删除，这里填空
* 参数 duration, 长整数型, , 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
*/
CQAPI(int32_t) CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);
/*
* 置讨论组退出, 整数型, , Auth=140
* 参数 discussid, 长整数型, , 目标讨论组
*/
CQAPI(int32_t) CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);
/*
* 置好友添加请求, 整数型, , Auth=150
* 参数 responseflag, 文本型, , 请求事件收到的“反馈标识”参数
* 参数 responseoperation, 整数型, , 反馈类型 #请求_通过 或 #请求_拒绝
* 参数 remark, 文本型, 可空, 添加后的好友备注
*/
CQAPI(int32_t) CQ_setFriendAddRequest(int32_t AuthCode, const char *responseflag, int32_t responseoperation, const char *remark);
/*
* 置群添加请求, 整数型, , Auth=151
* 参数 responseflag, 文本型, , 请求事件收到的“反馈标识”参数
* 参数 requesttype, 整数型, , 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
* 参数 responseoperation, 整数型, , #请求_通过 或 #请求_拒绝
* 参数 reason, 文本型, 可空, 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
*/
CQAPI(int32_t) CQ_setGroupAddRequestV2(int32_t AuthCode, const char *responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);
/*
* 取群成员信息, 整数型, , Auth=130
* 参数 groupid, 长整数型, , 目标QQ所在群
* 参数 QQID, 长整数型, , 目标QQ
* 参数 nocache, 逻辑型, 可空, 默认为"false"，通常忽略本参数，仅在必要时使用
*/
CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache);
/*
* 取陌生人信息, 整数型, , Auth=131
* 参数 QQID, 长整数型, , 目标QQ
* 参数 nocache, 逻辑型, 可空, 默认为"false"，通常忽略本参数，仅在必要时使用
*/
CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);
/*
* 添加日志_信息, 整数型, , 成功返回日志ID
* 参数 priority, 整数型, ,优先级
* 参数 category, 文本型, ,日志类型
* 参数 content, 文本型, ,日志内容
*/
CQAPI(int32_t) CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);
/*
* 取Cookies, 文本型, , Auth=20 慎用,此接口需要严格授权
*/
CQAPI(const char *) CQ_getCookies(int32_t AuthCode);
/*
* 取CsrfToken, 整数型, , Auth=20 即QQ网页用到的bkn/g_tk等 慎用,此接口需要严格授权
*/
CQAPI(int32_t) CQ_getCsrfToken(int32_t AuthCode);
/*
* 取登录QQ, 长整数型, , 
*/
CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);
/*
* 取登录昵称, 文本型, ,
*/
CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);
/*
* 取应用目录, 文本型, , 返回的路径末尾带"\"
*/
CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);
/*
* 置致命错误提示, 整数型, , 
* 参数 errorinfo, 文本型, ,错误信息
*/
CQAPI(int32_t) CQ_setFatal(int32_t AuthCode, const char *errorinfo);
