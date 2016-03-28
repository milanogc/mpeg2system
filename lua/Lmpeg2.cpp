/*
** Lua binding: mpeg2
** Generated automatically by tolua++-1.0.4 on 02/25/05 09:41:41.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_mpeg2_open (lua_State* tolua_S);

#include "Chunk.h"
#include "Iterator.h"
#include "Descriptor.h"
#include "PatSection.h"
#include "PmtSection.h"
#include "TSPacket.h"
#include "PesPacket.h"
#include "Descriptor.h"
#include "Section.h"
#include "PsiSection.h"
#include "PatSection.h"
#include "PmtSection.h"
#include "ApplicationSignallingDescriptor.h"
#include "AssociationTagDescriptor.h"
#include "CarouselIdentifierDescriptor.h"
#include "DataBroadcastIdDescriptor.h"
#include "StreamIdentifierDescriptor.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Iterator_PmtSection__Stream_ (lua_State* tolua_S)
{
 Iterator<PmtSection::Stream>* self = (Iterator<PmtSection::Stream>*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PatSection__Program (lua_State* tolua_S)
{
 PatSection::Program* self = (PatSection::Program*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_DataBroadcastIdDescriptor (lua_State* tolua_S)
{
 DataBroadcastIdDescriptor* self = (DataBroadcastIdDescriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Iterator_PatSection__Program_ (lua_State* tolua_S)
{
 Iterator<PatSection::Program>* self = (Iterator<PatSection::Program>*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Descriptor (lua_State* tolua_S)
{
 Descriptor* self = (Descriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Section (lua_State* tolua_S)
{
 Section* self = (Section*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Iterator_Descriptor_ (lua_State* tolua_S)
{
 Iterator<Descriptor>* self = (Iterator<Descriptor>*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_ApplicationSignallingDescriptor (lua_State* tolua_S)
{
 ApplicationSignallingDescriptor* self = (ApplicationSignallingDescriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PesPacket (lua_State* tolua_S)
{
 PesPacket* self = (PesPacket*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_TSPacket (lua_State* tolua_S)
{
 TSPacket* self = (TSPacket*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_StreamIdentifierDescriptor (lua_State* tolua_S)
{
 StreamIdentifierDescriptor* self = (StreamIdentifierDescriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_AssociationTagDescriptor (lua_State* tolua_S)
{
 AssociationTagDescriptor* self = (AssociationTagDescriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_CarouselIdentifierDescriptor (lua_State* tolua_S)
{
 CarouselIdentifierDescriptor* self = (CarouselIdentifierDescriptor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PmtSection (lua_State* tolua_S)
{
 PmtSection* self = (PmtSection*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Chunk (lua_State* tolua_S)
{
 Chunk* self = (Chunk*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PsiSection (lua_State* tolua_S)
{
 PsiSection* self = (PsiSection*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PmtSection__Stream (lua_State* tolua_S)
{
 PmtSection::Stream* self = (PmtSection::Stream*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_PatSection (lua_State* tolua_S)
{
 PatSection* self = (PatSection*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Iterator<PmtSection::Stream>");
 tolua_usertype(tolua_S,"PatSection::Program");
 tolua_usertype(tolua_S,"DataBroadcastIdDescriptor");
 tolua_usertype(tolua_S,"<Descriptor>");
 tolua_usertype(tolua_S,"<PmtSection::Stream>");
 tolua_usertype(tolua_S,"Iterator<PatSection::Program>");
 tolua_usertype(tolua_S,"Descriptor");
 tolua_usertype(tolua_S,"Section");
 tolua_usertype(tolua_S,"Iterator<Descriptor>");
 tolua_usertype(tolua_S,"ApplicationSignallingDescriptor");
 tolua_usertype(tolua_S,"PesPacket");
 tolua_usertype(tolua_S,"PsiSection");
 tolua_usertype(tolua_S,"CarouselIdentifierDescriptor");
 tolua_usertype(tolua_S,"StreamIdentifierDescriptor");
 tolua_usertype(tolua_S,"AssociationTagDescriptor");
 tolua_usertype(tolua_S,"PmtSection::Stream");
 tolua_usertype(tolua_S,"PmtSection");
 tolua_usertype(tolua_S,"Chunk");
 tolua_usertype(tolua_S,"TSPacket");
 tolua_usertype(tolua_S,"PatSection");
 tolua_usertype(tolua_S,"<PatSection::Program>");
}

/* method: new of class  Chunk */
static int tolua_mpeg2_Chunk_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Chunk",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned l = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  Chunk* tolua_ret = (Chunk*)  new Chunk(d,l);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Chunk");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  Chunk */
static int tolua_mpeg2_Chunk_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Chunk",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned l = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  Chunk* tolua_ret = (Chunk*)  new Chunk(d,l);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Chunk");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Chunk */
static int tolua_mpeg2_Chunk_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Chunk* self = (Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getData of class  Chunk */
static int tolua_mpeg2_Chunk_getData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Chunk* self = (const Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getData'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getData();
 tolua_pushlstring(tolua_S,(const char*)tolua_ret,self->getDataLength());
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getData'.",&tolua_err);
 return 0;
#endif
}

/* method: isAllocated of class  Chunk */
static int tolua_mpeg2_Chunk_isAllocated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Chunk* self = (const Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAllocated'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isAllocated();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAllocated'.",&tolua_err);
 return 0;
#endif
}

/* method: setData of class  Chunk */
static int tolua_mpeg2_Chunk_setData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Chunk",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Chunk* self = (Chunk*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned l = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setData'",NULL);
#endif
 {
  self->setData(d,l);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setData'.",&tolua_err);
 return 0;
#endif
}

/* method: getDataLength of class  Chunk */
static int tolua_mpeg2_Chunk_getDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Chunk* self = (const Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDataLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getDataLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDataLength'.",&tolua_err);
 return 0;
#endif
}

/* method: finalize of class  Chunk */
static int tolua_mpeg2_Chunk_finalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Chunk* self = (Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'finalize'",NULL);
#endif
 {
  self->finalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'finalize'.",&tolua_err);
 return 0;
#endif
}

/* method: verify of class  Chunk */
static int tolua_mpeg2_Chunk_verify00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Chunk",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Chunk* self = (const Chunk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'verify'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->verify();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'verify'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Iterator<Descriptor> */
static int tolua_mpeg2_DescriptorIterator_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<Descriptor>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<Descriptor>* self = (Iterator<Descriptor>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: hasNext of class  Iterator<Descriptor> */
static int tolua_mpeg2_DescriptorIterator_hasNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Iterator<Descriptor>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Iterator<Descriptor>* self = (const Iterator<Descriptor>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasNext'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasNext();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNext of class  Iterator<Descriptor> */
static int tolua_mpeg2_DescriptorIterator_getNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<Descriptor>",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<Descriptor>* self = (Iterator<Descriptor>*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNext'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getNext(length);
 tolua_pushlstring(tolua_S,(const char*)tolua_ret,length);
 tolua_pushnumber(tolua_S,(lua_Number)length);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNextLength of class  Iterator<Descriptor> */
static int tolua_mpeg2_DescriptorIterator_getNextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<Descriptor>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<Descriptor>* self = (Iterator<Descriptor>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNextLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getNextLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextLength'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Iterator<PatSection::Program> */
static int tolua_mpeg2_ProgramIterator_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PatSection::Program>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PatSection::Program>* self = (Iterator<PatSection::Program>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: hasNext of class  Iterator<PatSection::Program> */
static int tolua_mpeg2_ProgramIterator_hasNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Iterator<PatSection::Program>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Iterator<PatSection::Program>* self = (const Iterator<PatSection::Program>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasNext'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasNext();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNext of class  Iterator<PatSection::Program> */
static int tolua_mpeg2_ProgramIterator_getNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PatSection::Program>",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PatSection::Program>* self = (Iterator<PatSection::Program>*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNext'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getNext(length);
 tolua_pushlstring(tolua_S,(const char*)tolua_ret,length);
 tolua_pushnumber(tolua_S,(lua_Number)length);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNextLength of class  Iterator<PatSection::Program> */
static int tolua_mpeg2_ProgramIterator_getNextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PatSection::Program>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PatSection::Program>* self = (Iterator<PatSection::Program>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNextLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getNextLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextLength'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Iterator<PmtSection::Stream> */
static int tolua_mpeg2_StreamIterator_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PmtSection::Stream>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PmtSection::Stream>* self = (Iterator<PmtSection::Stream>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: hasNext of class  Iterator<PmtSection::Stream> */
static int tolua_mpeg2_StreamIterator_hasNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Iterator<PmtSection::Stream>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Iterator<PmtSection::Stream>* self = (const Iterator<PmtSection::Stream>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasNext'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasNext();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNext of class  Iterator<PmtSection::Stream> */
static int tolua_mpeg2_StreamIterator_getNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PmtSection::Stream>",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PmtSection::Stream>* self = (Iterator<PmtSection::Stream>*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNext'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getNext(length);
 tolua_pushlstring(tolua_S,(const char*)tolua_ret,length);
 tolua_pushnumber(tolua_S,(lua_Number)length);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNext'.",&tolua_err);
 return 0;
#endif
}

/* method: getNextLength of class  Iterator<PmtSection::Stream> */
static int tolua_mpeg2_StreamIterator_getNextLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Iterator<PmtSection::Stream>",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Iterator<PmtSection::Stream>* self = (Iterator<PmtSection::Stream>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNextLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getNextLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNextLength'.",&tolua_err);
 return 0;
#endif
}

/* get function: PACKET_SIZE of class  TSPacket */
static int tolua_get_TSPacket_PACKET_SIZE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)TSPacket::PACKET_SIZE);
 return 1;
}

/* get function: MAX_PAYLOAD_SIZE of class  TSPacket */
static int tolua_get_TSPacket_MAX_PAYLOAD_SIZE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)TSPacket::MAX_PAYLOAD_SIZE);
 return 1;
}

/* get function: STUFFING_BYTE of class  TSPacket */
static int tolua_get_TSPacket_STUFFING_BYTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)TSPacket::STUFFING_BYTE);
 return 1;
}

/* get function: SYNC_BYTE of class  TSPacket */
static int tolua_get_TSPacket_SYNC_BYTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)TSPacket::SYNC_BYTE);
 return 1;
}

/* method: new of class  TSPacket */
static int tolua_mpeg2_TSPacket_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  TSPacket* tolua_ret = (TSPacket*)  new TSPacket();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"TSPacket");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TSPacket */
static int tolua_mpeg2_TSPacket_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  TSPacket* tolua_ret = (TSPacket*)  new TSPacket();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TSPacket");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TSPacket */
static int tolua_mpeg2_TSPacket_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getSyncByte of class  TSPacket */
static int tolua_mpeg2_TSPacket_getSyncByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSyncByte'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSyncByte();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSyncByte'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportErrorIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportErrorIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportErrorIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getTransportErrorIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportErrorIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getPayloadUnitStartIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPayloadUnitStartIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPayloadUnitStartIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPayloadUnitStartIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPayloadUnitStartIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportPriority of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportPriority'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getTransportPriority();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportPriority'.",&tolua_err);
 return 0;
#endif
}

/* method: getPid of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPid'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getPid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPid'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportScramblingControl of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportScramblingControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportScramblingControl'",NULL);
#endif
 {
  ScramblingControl tolua_ret = (ScramblingControl)  self->getTransportScramblingControl();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportScramblingControl'.",&tolua_err);
 return 0;
#endif
}

/* method: getAdaptationFieldControl of class  TSPacket */
static int tolua_mpeg2_TSPacket_getAdaptationFieldControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAdaptationFieldControl'",NULL);
#endif
 {
  AdaptFieldControl tolua_ret = (AdaptFieldControl)  self->getAdaptationFieldControl();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAdaptationFieldControl'.",&tolua_err);
 return 0;
#endif
}

/* method: getContinuityCounter of class  TSPacket */
static int tolua_mpeg2_TSPacket_getContinuityCounter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContinuityCounter'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getContinuityCounter();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContinuityCounter'.",&tolua_err);
 return 0;
#endif
}

/* method: hasAdaptationField of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasAdaptationField00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAdaptationField'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasAdaptationField();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAdaptationField'.",&tolua_err);
 return 0;
#endif
}

/* method: getAdaptationFieldLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_getAdaptationFieldLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAdaptationFieldLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getAdaptationFieldLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAdaptationFieldLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getDiscontinuityIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_getDiscontinuityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDiscontinuityIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getDiscontinuityIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDiscontinuityIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getRandomAccessIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_getRandomAccessIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRandomAccessIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getRandomAccessIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRandomAccessIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getElementaryStreamPriorityIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_getElementaryStreamPriorityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElementaryStreamPriorityIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getElementaryStreamPriorityIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElementaryStreamPriorityIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getPcrFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPcrFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPcrFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPcrFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPcrFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getOpcrFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getOpcrFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpcrFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getOpcrFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpcrFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getSplicingPointFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getSplicingPointFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSplicingPointFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getSplicingPointFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSplicingPointFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportPrivateDataFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportPrivateDataFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportPrivateDataFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getTransportPrivateDataFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportPrivateDataFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getAdaptationFieldExtensionFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getAdaptationFieldExtensionFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAdaptationFieldExtensionFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getAdaptationFieldExtensionFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAdaptationFieldExtensionFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: hasPcr of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasPcr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasPcr'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasPcr();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasPcr'.",&tolua_err);
 return 0;
#endif
}

/* method: getPcrBase of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPcrBase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPcrBase'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getPcrBase();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPcrBase'.",&tolua_err);
 return 0;
#endif
}

/* method: getPcrExtension of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPcrExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPcrExtension'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPcrExtension();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPcrExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: hasOriginalPcr of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasOriginalPcr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasOriginalPcr'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasOriginalPcr();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasOriginalPcr'.",&tolua_err);
 return 0;
#endif
}

/* method: getOriginalPcrBase of class  TSPacket */
static int tolua_mpeg2_TSPacket_getOriginalPcrBase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalPcrBase'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getOriginalPcrBase();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOriginalPcrBase'.",&tolua_err);
 return 0;
#endif
}

/* method: getOriginalPcrExtension of class  TSPacket */
static int tolua_mpeg2_TSPacket_getOriginalPcrExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalPcrExtension'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getOriginalPcrExtension();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOriginalPcrExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: hasSpliceCountdown of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasSpliceCountdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasSpliceCountdown'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasSpliceCountdown();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasSpliceCountdown'.",&tolua_err);
 return 0;
#endif
}

/* method: getSpliceCountdown of class  TSPacket */
static int tolua_mpeg2_TSPacket_getSpliceCountdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpliceCountdown'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSpliceCountdown();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpliceCountdown'.",&tolua_err);
 return 0;
#endif
}

/* method: hasTransportPrivateData of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasTransportPrivateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasTransportPrivateData'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasTransportPrivateData();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasTransportPrivateData'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportPrivateDataLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportPrivateDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportPrivateDataLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTransportPrivateDataLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportPrivateDataLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportDataBytes of class  TSPacket */
static int tolua_mpeg2_TSPacket_getTransportDataBytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportDataBytes'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getTransportDataBytes(length);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)length);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportDataBytes'.",&tolua_err);
 return 0;
#endif
}

/* method: hasAdaptationFieldExtension of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasAdaptationFieldExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAdaptationFieldExtension'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasAdaptationFieldExtension();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAdaptationFieldExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: getAdaptationFieldExtensionLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_getAdaptationFieldExtensionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAdaptationFieldExtensionLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getAdaptationFieldExtensionLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAdaptationFieldExtensionLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getLtwFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getLtwFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLtwFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getLtwFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLtwFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getPiecewiseRateFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPiecewiseRateFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPiecewiseRateFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPiecewiseRateFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPiecewiseRateFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getSeamlessSpliceFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getSeamlessSpliceFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSeamlessSpliceFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getSeamlessSpliceFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSeamlessSpliceFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: hasLtw of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasLtw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasLtw'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasLtw();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasLtw'.",&tolua_err);
 return 0;
#endif
}

/* method: getLtwValidFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_getLtwValidFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLtwValidFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getLtwValidFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLtwValidFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getLtwOffset of class  TSPacket */
static int tolua_mpeg2_TSPacket_getLtwOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLtwOffset'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getLtwOffset();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLtwOffset'.",&tolua_err);
 return 0;
#endif
}

/* method: hasPiecewiseRate of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasPiecewiseRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasPiecewiseRate'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasPiecewiseRate();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasPiecewiseRate'.",&tolua_err);
 return 0;
#endif
}

/* method: getPiecewiseRate of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPiecewiseRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPiecewiseRate'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPiecewiseRate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPiecewiseRate'.",&tolua_err);
 return 0;
#endif
}

/* method: hasSeamlessSplice of class  TSPacket */
static int tolua_mpeg2_TSPacket_hasSeamlessSplice00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasSeamlessSplice'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasSeamlessSplice();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasSeamlessSplice'.",&tolua_err);
 return 0;
#endif
}

/* method: getSpliceType of class  TSPacket */
static int tolua_mpeg2_TSPacket_getSpliceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpliceType'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSpliceType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpliceType'.",&tolua_err);
 return 0;
#endif
}

/* method: getDtsNextAu of class  TSPacket */
static int tolua_mpeg2_TSPacket_getDtsNextAu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDtsNextAu'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getDtsNextAu();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDtsNextAu'.",&tolua_err);
 return 0;
#endif
}

/* method: getPayloadLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPayloadLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPayloadLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPayloadLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPayloadLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getPayload of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPayload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned length;
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPayload'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getPayload(length);
 tolua_pushlstring(tolua_S,(const char*)tolua_ret,length);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPayload'.",&tolua_err);
 return 0;
#endif
}

/* method: getPayload of class  TSPacket */
static int tolua_mpeg2_TSPacket_getPayload01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const TSPacket* self = (const TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPayload'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getPayload(length);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)length);
 }
 }
 return 2;
tolua_lerror:
 return tolua_mpeg2_TSPacket_getPayload00(tolua_S);
}

/* method: setTransportErrorIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportErrorIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool transportError = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportErrorIndicator'",NULL);
#endif
 {
  self->setTransportErrorIndicator(transportError);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportErrorIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setPayloadUnitStartIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPayloadUnitStartIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool payloadUnitStart = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPayloadUnitStartIndicator'",NULL);
#endif
 {
  self->setPayloadUnitStartIndicator(payloadUnitStart);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPayloadUnitStartIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportPriority of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool transportPriority = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportPriority'",NULL);
#endif
 {
  self->setTransportPriority(transportPriority);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportPriority'.",&tolua_err);
 return 0;
#endif
}

/* method: setPid of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  int pid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPid'",NULL);
#endif
 {
  self->setPid(pid);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPid'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportScramblingControl of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportScramblingControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  ScramblingControl scramblingControl = ((ScramblingControl) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportScramblingControl'",NULL);
#endif
 {
  self->setTransportScramblingControl(scramblingControl);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportScramblingControl'.",&tolua_err);
 return 0;
#endif
}

/* method: setAdaptationFieldControl of class  TSPacket */
static int tolua_mpeg2_TSPacket_setAdaptationFieldControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  AdaptFieldControl adaptionFieldControl = ((AdaptFieldControl) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAdaptationFieldControl'",NULL);
#endif
 {
  self->setAdaptationFieldControl(adaptionFieldControl);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAdaptationFieldControl'.",&tolua_err);
 return 0;
#endif
}

/* method: setContinuityCounter of class  TSPacket */
static int tolua_mpeg2_TSPacket_setContinuityCounter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned continuityCounter = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContinuityCounter'",NULL);
#endif
 {
  self->setContinuityCounter(continuityCounter);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContinuityCounter'.",&tolua_err);
 return 0;
#endif
}

/* method: incContinuityCounter of class  TSPacket */
static int tolua_mpeg2_TSPacket_incContinuityCounter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incContinuityCounter'",NULL);
#endif
 {
  self->incContinuityCounter();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incContinuityCounter'.",&tolua_err);
 return 0;
#endif
}

/* method: setAdaptationFieldLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_setAdaptationFieldLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned aFieldLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAdaptationFieldLength'",NULL);
#endif
 {
  self->setAdaptationFieldLength(aFieldLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAdaptationFieldLength'.",&tolua_err);
 return 0;
#endif
}

/* method: setDiscontinuityIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_setDiscontinuityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool indicator = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDiscontinuityIndicator'",NULL);
#endif
 {
  self->setDiscontinuityIndicator(indicator);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDiscontinuityIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setRandomAccessIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_setRandomAccessIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool indicator = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRandomAccessIndicator'",NULL);
#endif
 {
  self->setRandomAccessIndicator(indicator);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRandomAccessIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setElementaryStreamPriorityIndicator of class  TSPacket */
static int tolua_mpeg2_TSPacket_setElementaryStreamPriorityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool indicator = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setElementaryStreamPriorityIndicator'",NULL);
#endif
 {
  self->setElementaryStreamPriorityIndicator(indicator);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setElementaryStreamPriorityIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setPcrFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPcrFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPcrFlag'",NULL);
#endif
 {
  self->setPcrFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPcrFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setOpcrFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setOpcrFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpcrFlag'",NULL);
#endif
 {
  self->setOpcrFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpcrFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setSplicingPointFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setSplicingPointFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSplicingPointFlag'",NULL);
#endif
 {
  self->setSplicingPointFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSplicingPointFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportPrivateDataFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportPrivateDataFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportPrivateDataFlag'",NULL);
#endif
 {
  self->setTransportPrivateDataFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportPrivateDataFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setAdaptationFieldExtensionFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setAdaptationFieldExtensionFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAdaptationFieldExtensionFlag'",NULL);
#endif
 {
  self->setAdaptationFieldExtensionFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAdaptationFieldExtensionFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setPcrBase of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPcrBase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long pcrBase = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPcrBase'",NULL);
#endif
 {
  self->setPcrBase(pcrBase);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPcrBase'.",&tolua_err);
 return 0;
#endif
}

/* method: setPcrExtension of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPcrExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned pcrExtension = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPcrExtension'",NULL);
#endif
 {
  self->setPcrExtension(pcrExtension);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPcrExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: setOriginalPcrBase of class  TSPacket */
static int tolua_mpeg2_TSPacket_setOriginalPcrBase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long pcrBase = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOriginalPcrBase'",NULL);
#endif
 {
  self->setOriginalPcrBase(pcrBase);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOriginalPcrBase'.",&tolua_err);
 return 0;
#endif
}

/* method: setOriginalPcrExtension of class  TSPacket */
static int tolua_mpeg2_TSPacket_setOriginalPcrExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned pcrExtension = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOriginalPcrExtension'",NULL);
#endif
 {
  self->setOriginalPcrExtension(pcrExtension);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOriginalPcrExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: setSpliceCountdown of class  TSPacket */
static int tolua_mpeg2_TSPacket_setSpliceCountdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned countdown = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpliceCountdown'",NULL);
#endif
 {
  self->setSpliceCountdown(countdown);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpliceCountdown'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportPrivateDataLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportPrivateDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned dataLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportPrivateDataLength'",NULL);
#endif
 {
  self->setTransportPrivateDataLength(dataLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportPrivateDataLength'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportDataBytes of class  TSPacket */
static int tolua_mpeg2_TSPacket_setTransportDataBytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* dataBytes = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned dataLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportDataBytes'",NULL);
#endif
 {
  self->setTransportDataBytes(dataBytes,dataLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportDataBytes'.",&tolua_err);
 return 0;
#endif
}

/* method: setAdaptationFieldExtensionLength of class  TSPacket */
static int tolua_mpeg2_TSPacket_setAdaptationFieldExtensionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAdaptationFieldExtensionLength'",NULL);
#endif
 {
  self->setAdaptationFieldExtensionLength(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAdaptationFieldExtensionLength'.",&tolua_err);
 return 0;
#endif
}

/* method: setLtwFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setLtwFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLtwFlag'",NULL);
#endif
 {
  self->setLtwFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLtwFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setPiecewiseRateFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPiecewiseRateFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPiecewiseRateFlag'",NULL);
#endif
 {
  self->setPiecewiseRateFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPiecewiseRateFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setSeamlessSpliceFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setSeamlessSpliceFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSeamlessSpliceFlag'",NULL);
#endif
 {
  self->setSeamlessSpliceFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSeamlessSpliceFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setLtwValidFlag of class  TSPacket */
static int tolua_mpeg2_TSPacket_setLtwValidFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLtwValidFlag'",NULL);
#endif
 {
  self->setLtwValidFlag(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLtwValidFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: setLtwOffset of class  TSPacket */
static int tolua_mpeg2_TSPacket_setLtwOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned offset = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLtwOffset'",NULL);
#endif
 {
  self->setLtwOffset(offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLtwOffset'.",&tolua_err);
 return 0;
#endif
}

/* method: setPiecewiseRate of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPiecewiseRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned rate = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPiecewiseRate'",NULL);
#endif
 {
  self->setPiecewiseRate(rate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPiecewiseRate'.",&tolua_err);
 return 0;
#endif
}

/* method: setSpliceType of class  TSPacket */
static int tolua_mpeg2_TSPacket_setSpliceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned spliceType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpliceType'",NULL);
#endif
 {
  self->setSpliceType(spliceType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpliceType'.",&tolua_err);
 return 0;
#endif
}

/* method: setDtsNextAu of class  TSPacket */
static int tolua_mpeg2_TSPacket_setDtsNextAu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long dtsNextAu = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDtsNextAu'",NULL);
#endif
 {
  self->setDtsNextAu(dtsNextAu);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDtsNextAu'.",&tolua_err);
 return 0;
#endif
}

/* method: setPayload of class  TSPacket */
static int tolua_mpeg2_TSPacket_setPayload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TSPacket",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TSPacket* self = (TSPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPayload'",NULL);
#endif
 {
  self->setPayload(d,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPayload'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  PesPacket */
static int tolua_mpeg2_PesPacket_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PesPacket* tolua_ret = (PesPacket*)  new PesPacket();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PesPacket");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  PesPacket */
static int tolua_mpeg2_PesPacket_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PesPacket* tolua_ret = (PesPacket*)  new PesPacket();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PesPacket");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  PesPacket */
static int tolua_mpeg2_PesPacket_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PesPacket* self = (PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getPacketStartCodePrefix of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPacketStartCodePrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPacketStartCodePrefix'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPacketStartCodePrefix();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPacketStartCodePrefix'.",&tolua_err);
 return 0;
#endif
}

/* method: getStreamId of class  PesPacket */
static int tolua_mpeg2_PesPacket_getStreamId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStreamId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getStreamId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStreamId'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesPacketLength of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesPacketLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesPacketLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPesPacketLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesPacketLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesScramblingControl of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesScramblingControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesScramblingControl'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPesScramblingControl();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesScramblingControl'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesPriority of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesPriority'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPesPriority();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesPriority'.",&tolua_err);
 return 0;
#endif
}

/* method: getDataAlignmentIndicator of class  PesPacket */
static int tolua_mpeg2_PesPacket_getDataAlignmentIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDataAlignmentIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getDataAlignmentIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDataAlignmentIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getCopyright of class  PesPacket */
static int tolua_mpeg2_PesPacket_getCopyright00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCopyright'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getCopyright();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCopyright'.",&tolua_err);
 return 0;
#endif
}

/* method: getOriginalOrCopy of class  PesPacket */
static int tolua_mpeg2_PesPacket_getOriginalOrCopy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalOrCopy'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getOriginalOrCopy();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOriginalOrCopy'.",&tolua_err);
 return 0;
#endif
}

/* method: getPtsDtsFlags of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPtsDtsFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPtsDtsFlags'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPtsDtsFlags();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPtsDtsFlags'.",&tolua_err);
 return 0;
#endif
}

/* method: getEscrFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getEscrFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEscrFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getEscrFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEscrFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getEsRateFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getEsRateFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEsRateFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getEsRateFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEsRateFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getDsmTrickModeFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getDsmTrickModeFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDsmTrickModeFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getDsmTrickModeFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDsmTrickModeFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getAdditionalCopyInfoFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getAdditionalCopyInfoFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAdditionalCopyInfoFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getAdditionalCopyInfoFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAdditionalCopyInfoFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesCrcFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesCrcFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesCrcFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPesCrcFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesCrcFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesExtensionFlag of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesExtensionFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesExtensionFlag'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPesExtensionFlag();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesExtensionFlag'.",&tolua_err);
 return 0;
#endif
}

/* method: getPesHeaderDataLength of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPesHeaderDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPesHeaderDataLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getPesHeaderDataLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPesHeaderDataLength'.",&tolua_err);
 return 0;
#endif
}

/* method: hasPts of class  PesPacket */
static int tolua_mpeg2_PesPacket_hasPts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasPts'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasPts();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasPts'.",&tolua_err);
 return 0;
#endif
}

/* method: getPts of class  PesPacket */
static int tolua_mpeg2_PesPacket_getPts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPts'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getPts();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPts'.",&tolua_err);
 return 0;
#endif
}

/* method: hasDts of class  PesPacket */
static int tolua_mpeg2_PesPacket_hasDts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasDts'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasDts();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasDts'.",&tolua_err);
 return 0;
#endif
}

/* method: getDts of class  PesPacket */
static int tolua_mpeg2_PesPacket_getDts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDts'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getDts();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDts'.",&tolua_err);
 return 0;
#endif
}

/* method: hasEscr of class  PesPacket */
static int tolua_mpeg2_PesPacket_hasEscr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasEscr'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasEscr();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasEscr'.",&tolua_err);
 return 0;
#endif
}

/* method: getEscrBase of class  PesPacket */
static int tolua_mpeg2_PesPacket_getEscrBase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEscrBase'",NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->getEscrBase();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEscrBase'.",&tolua_err);
 return 0;
#endif
}

/* method: getEscrExtension of class  PesPacket */
static int tolua_mpeg2_PesPacket_getEscrExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEscrExtension'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getEscrExtension();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEscrExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: verify of class  PesPacket */
static int tolua_mpeg2_PesPacket_verify00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PesPacket* self = (const PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'verify'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->verify();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'verify'.",&tolua_err);
 return 0;
#endif
}

/* method: setPacketStartCodePrefix of class  PesPacket */
static int tolua_mpeg2_PesPacket_setPacketStartCodePrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PesPacket* self = (PesPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned prefix = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPacketStartCodePrefix'",NULL);
#endif
 {
  self->setPacketStartCodePrefix(prefix);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPacketStartCodePrefix'.",&tolua_err);
 return 0;
#endif
}

/* method: setStreamId of class  PesPacket */
static int tolua_mpeg2_PesPacket_setStreamId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PesPacket* self = (PesPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStreamId'",NULL);
#endif
 {
  self->setStreamId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStreamId'.",&tolua_err);
 return 0;
#endif
}

/* method: setPesPacketLength of class  PesPacket */
static int tolua_mpeg2_PesPacket_setPesPacketLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PesPacket* self = (PesPacket*)  tolua_tousertype(tolua_S,1,0);
  unsigned packetLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPesPacketLength'",NULL);
#endif
 {
  self->setPesPacketLength(packetLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPesPacketLength'.",&tolua_err);
 return 0;
#endif
}

/* method: finalize of class  PesPacket */
static int tolua_mpeg2_PesPacket_finalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PesPacket",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PesPacket* self = (PesPacket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'finalize'",NULL);
#endif
 {
  self->finalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'finalize'.",&tolua_err);
 return 0;
#endif
}

/* get function: MAX_LENGTH of class  Descriptor */
static int tolua_get_Descriptor_MAX_LENGTH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Descriptor::MAX_LENGTH);
 return 1;
}

/* method: new of class  Descriptor */
static int tolua_mpeg2_Descriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Descriptor",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
 {
  Descriptor* tolua_ret = (Descriptor*)  new Descriptor(d);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Descriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  Descriptor */
static int tolua_mpeg2_Descriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Descriptor",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned char* d = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
 {
  Descriptor* tolua_ret = (Descriptor*)  new Descriptor(d);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Descriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Descriptor */
static int tolua_mpeg2_Descriptor_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  Descriptor* tolua_ret = (Descriptor*)  new Descriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Descriptor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_mpeg2_Descriptor_new00(tolua_S);
}

/* method: new_local of class  Descriptor */
static int tolua_mpeg2_Descriptor_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  Descriptor* tolua_ret = (Descriptor*)  new Descriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Descriptor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_mpeg2_Descriptor_new00_local(tolua_S);
}

/* method: delete of class  Descriptor */
static int tolua_mpeg2_Descriptor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Descriptor* self = (Descriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getDescriptorTag of class  Descriptor */
static int tolua_mpeg2_Descriptor_getDescriptorTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Descriptor* self = (const Descriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescriptorTag'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getDescriptorTag();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescriptorTag'.",&tolua_err);
 return 0;
#endif
}

/* method: getDescriptorLength of class  Descriptor */
static int tolua_mpeg2_Descriptor_getDescriptorLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Descriptor* self = (const Descriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescriptorLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getDescriptorLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescriptorLength'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Section */
static int tolua_mpeg2_Section_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Section* tolua_ret = (Section*)  new Section();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Section");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  Section */
static int tolua_mpeg2_Section_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Section* tolua_ret = (Section*)  new Section();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Section");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Section */
static int tolua_mpeg2_Section_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Section* self = (Section*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getTableId of class  Section */
static int tolua_mpeg2_Section_getTableId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Section* self = (const Section*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTableId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTableId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTableId'.",&tolua_err);
 return 0;
#endif
}

/* method: getSectionSyntaxIndicator of class  Section */
static int tolua_mpeg2_Section_getSectionSyntaxIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Section* self = (const Section*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSectionSyntaxIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getSectionSyntaxIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSectionSyntaxIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getPrivateIndicator of class  Section */
static int tolua_mpeg2_Section_getPrivateIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Section* self = (const Section*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPrivateIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getPrivateIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPrivateIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getSectionLength of class  Section */
static int tolua_mpeg2_Section_getSectionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Section",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Section* self = (const Section*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSectionLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSectionLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSectionLength'.",&tolua_err);
 return 0;
#endif
}

/* method: setSectionLength of class  Section */
static int tolua_mpeg2_Section_setSectionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Section",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Section* self = (Section*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSectionLength'",NULL);
#endif
 {
  self->setSectionLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSectionLength'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  PsiSection */
static int tolua_mpeg2_PsiSection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PsiSection* tolua_ret = (PsiSection*)  new PsiSection();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PsiSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  PsiSection */
static int tolua_mpeg2_PsiSection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PsiSection* tolua_ret = (PsiSection*)  new PsiSection();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PsiSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  PsiSection */
static int tolua_mpeg2_PsiSection_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getTableIdExtension of class  PsiSection */
static int tolua_mpeg2_PsiSection_getTableIdExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTableIdExtension'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTableIdExtension();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTableIdExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: getVersionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_getVersionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersionNumber'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getVersionNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: getCurrentNextIndicator of class  PsiSection */
static int tolua_mpeg2_PsiSection_getCurrentNextIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentNextIndicator'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getCurrentNextIndicator();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentNextIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: getSectionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_getSectionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSectionNumber'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSectionNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSectionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: getLastSectionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_getLastSectionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastSectionNumber'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getLastSectionNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastSectionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: getCrc32 of class  PsiSection */
static int tolua_mpeg2_PsiSection_getCrc3200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PsiSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PsiSection* self = (const PsiSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCrc32'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getCrc32();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCrc32'.",&tolua_err);
 return 0;
#endif
}

/* method: setTableIdExtension of class  PsiSection */
static int tolua_mpeg2_PsiSection_setTableIdExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTableIdExtension'",NULL);
#endif
 {
  self->setTableIdExtension(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTableIdExtension'.",&tolua_err);
 return 0;
#endif
}

/* method: setVersionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_setVersionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned version = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVersionNumber'",NULL);
#endif
 {
  self->setVersionNumber(version);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVersionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: setCurrentNextIndicator of class  PsiSection */
static int tolua_mpeg2_PsiSection_setCurrentNextIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
  bool indicator = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCurrentNextIndicator'",NULL);
#endif
 {
  self->setCurrentNextIndicator(indicator);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCurrentNextIndicator'.",&tolua_err);
 return 0;
#endif
}

/* method: setSectionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_setSectionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned number = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSectionNumber'",NULL);
#endif
 {
  self->setSectionNumber(number);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSectionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: setLastSectionNumber of class  PsiSection */
static int tolua_mpeg2_PsiSection_setLastSectionNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PsiSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PsiSection* self = (PsiSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned number = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLastSectionNumber'",NULL);
#endif
 {
  self->setLastSectionNumber(number);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLastSectionNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Program */
static int tolua_mpeg2_PatSection_Program_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PatSection::Program",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PatSection::Program* tolua_ret = (PatSection::Program*)  new PatSection::Program();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PatSection::Program");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  Program */
static int tolua_mpeg2_PatSection_Program_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PatSection::Program",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PatSection::Program* tolua_ret = (PatSection::Program*)  new PatSection::Program();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PatSection::Program");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Program */
static int tolua_mpeg2_PatSection_Program_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection::Program",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection::Program* self = (PatSection::Program*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getProgramNumber of class  Program */
static int tolua_mpeg2_PatSection_Program_getProgramNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PatSection::Program",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PatSection::Program* self = (const PatSection::Program*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramNumber'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getProgramNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: getPid of class  Program */
static int tolua_mpeg2_PatSection_Program_getPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PatSection::Program",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PatSection::Program* self = (const PatSection::Program*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPid'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getPid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPid'.",&tolua_err);
 return 0;
#endif
}

/* method: setProgramNumber of class  Program */
static int tolua_mpeg2_PatSection_Program_setProgramNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection::Program",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection::Program* self = (PatSection::Program*)  tolua_tousertype(tolua_S,1,0);
  unsigned number = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgramNumber'",NULL);
#endif
 {
  self->setProgramNumber(number);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgramNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: setPid of class  Program */
static int tolua_mpeg2_PatSection_Program_setPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection::Program",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection::Program* self = (PatSection::Program*)  tolua_tousertype(tolua_S,1,0);
  int pid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPid'",NULL);
#endif
 {
  self->setPid(pid);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPid'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  PatSection */
static int tolua_mpeg2_PatSection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PatSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PatSection* tolua_ret = (PatSection*)  new PatSection();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PatSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  PatSection */
static int tolua_mpeg2_PatSection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PatSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PatSection* tolua_ret = (PatSection*)  new PatSection();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PatSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  PatSection */
static int tolua_mpeg2_PatSection_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection* self = (PatSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getProgramsIterator of class  PatSection */
static int tolua_mpeg2_PatSection_getProgramsIterator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PatSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PatSection* self = (const PatSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramsIterator'",NULL);
#endif
 {
  Iterator<PatSection::Program>* tolua_ret = (Iterator<PatSection::Program>*)  self->getProgramsIterator();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Iterator<PatSection::Program>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramsIterator'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransportStreamId of class  PatSection */
static int tolua_mpeg2_PatSection_getTransportStreamId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PatSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PatSection* self = (const PatSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransportStreamId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTransportStreamId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransportStreamId'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransportStreamId of class  PatSection */
static int tolua_mpeg2_PatSection_setTransportStreamId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection* self = (PatSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransportStreamId'",NULL);
#endif
 {
  self->setTransportStreamId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransportStreamId'.",&tolua_err);
 return 0;
#endif
}

/* method: appendProgram of class  PatSection */
static int tolua_mpeg2_PatSection_appendProgram00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PatSection",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PatSection* self = (PatSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* programData = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned programDataLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendProgram'",NULL);
#endif
 {
  self->appendProgram(programData,programDataLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendProgram'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PmtSection::Stream* tolua_ret = (PmtSection::Stream*)  new PmtSection::Stream();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PmtSection::Stream");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PmtSection::Stream* tolua_ret = (PmtSection::Stream*)  new PmtSection::Stream();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PmtSection::Stream");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getStreamType of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_getStreamType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection::Stream* self = (const PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStreamType'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getStreamType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStreamType'.",&tolua_err);
 return 0;
#endif
}

/* method: getElementaryPid of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_getElementaryPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection::Stream* self = (const PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElementaryPid'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getElementaryPid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElementaryPid'.",&tolua_err);
 return 0;
#endif
}

/* method: getEsInfoLength of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_getEsInfoLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection::Stream* self = (const PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEsInfoLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getEsInfoLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEsInfoLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getDescriptorsIterator of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_getDescriptorsIterator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection::Stream* self = (const PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescriptorsIterator'",NULL);
#endif
 {
  Iterator<Descriptor>* tolua_ret = (Iterator<Descriptor>*)  self->getDescriptorsIterator();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Iterator<Descriptor>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescriptorsIterator'.",&tolua_err);
 return 0;
#endif
}

/* method: setStreamType of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_setStreamType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection::Stream* self = (PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
  unsigned type = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStreamType'",NULL);
#endif
 {
  self->setStreamType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStreamType'.",&tolua_err);
 return 0;
#endif
}

/* method: setElementaryPid of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_setElementaryPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection::Stream* self = (PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
  int pid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setElementaryPid'",NULL);
#endif
 {
  self->setElementaryPid(pid);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setElementaryPid'.",&tolua_err);
 return 0;
#endif
}

/* method: setEsInfoLength of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_setEsInfoLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection::Stream* self = (PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEsInfoLength'",NULL);
#endif
 {
  self->setEsInfoLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEsInfoLength'.",&tolua_err);
 return 0;
#endif
}

/* method: appendDescriptor of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_appendDescriptor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection::Stream* self = (PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* descriptorData = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned descriptorDataLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendDescriptor'",NULL);
#endif
 {
  self->appendDescriptor(descriptorData,descriptorDataLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendDescriptor'.",&tolua_err);
 return 0;
#endif
}

/* method: appendDescriptor of class  Stream */
static int tolua_mpeg2_PmtSection_Stream_appendDescriptor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Descriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PmtSection::Stream* self = (PmtSection::Stream*)  tolua_tousertype(tolua_S,1,0);
  Descriptor* descriptorData = ((Descriptor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendDescriptor'",NULL);
#endif
 {
  self->appendDescriptor(*descriptorData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_mpeg2_PmtSection_Stream_appendDescriptor00(tolua_S);
}

/* method: new of class  PmtSection */
static int tolua_mpeg2_PmtSection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PmtSection* tolua_ret = (PmtSection*)  new PmtSection();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PmtSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  PmtSection */
static int tolua_mpeg2_PmtSection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PmtSection* tolua_ret = (PmtSection*)  new PmtSection();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"PmtSection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getProgramNumber of class  PmtSection */
static int tolua_mpeg2_PmtSection_getProgramNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection* self = (const PmtSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramNumber'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getProgramNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: getPcrPid of class  PmtSection */
static int tolua_mpeg2_PmtSection_getPcrPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection* self = (const PmtSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPcrPid'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getPcrPid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPcrPid'.",&tolua_err);
 return 0;
#endif
}

/* method: getProgramInfoLength of class  PmtSection */
static int tolua_mpeg2_PmtSection_getProgramInfoLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection* self = (const PmtSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramInfoLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getProgramInfoLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramInfoLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getDescriptorsIterator of class  PmtSection */
static int tolua_mpeg2_PmtSection_getDescriptorsIterator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection* self = (const PmtSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescriptorsIterator'",NULL);
#endif
 {
  Iterator<Descriptor>* tolua_ret = (Iterator<Descriptor>*)  self->getDescriptorsIterator();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Iterator<Descriptor>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescriptorsIterator'.",&tolua_err);
 return 0;
#endif
}

/* method: getStreamsIterator of class  PmtSection */
static int tolua_mpeg2_PmtSection_getStreamsIterator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PmtSection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PmtSection* self = (const PmtSection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStreamsIterator'",NULL);
#endif
 {
  Iterator<PmtSection::Stream>* tolua_ret = (Iterator<PmtSection::Stream>*)  self->getStreamsIterator();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Iterator<PmtSection::Stream>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStreamsIterator'.",&tolua_err);
 return 0;
#endif
}

/* method: setProgramNumber of class  PmtSection */
static int tolua_mpeg2_PmtSection_setProgramNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgramNumber'",NULL);
#endif
 {
  self->setProgramNumber(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgramNumber'.",&tolua_err);
 return 0;
#endif
}

/* method: setPcrPid of class  PmtSection */
static int tolua_mpeg2_PmtSection_setPcrPid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  int pid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPcrPid'",NULL);
#endif
 {
  self->setPcrPid(pid);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPcrPid'.",&tolua_err);
 return 0;
#endif
}

/* method: setProgramInfoLength of class  PmtSection */
static int tolua_mpeg2_PmtSection_setProgramInfoLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgramInfoLength'",NULL);
#endif
 {
  self->setProgramInfoLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgramInfoLength'.",&tolua_err);
 return 0;
#endif
}

/* method: appendDescriptor of class  PmtSection */
static int tolua_mpeg2_PmtSection_appendDescriptor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* descriptorData = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned descriptorLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendDescriptor'",NULL);
#endif
 {
  self->appendDescriptor(descriptorData,descriptorLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendDescriptor'.",&tolua_err);
 return 0;
#endif
}

/* method: appendStream of class  PmtSection */
static int tolua_mpeg2_PmtSection_appendStream00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* streamData = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned streamLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendStream'",NULL);
#endif
 {
  self->appendStream(streamData,streamLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendStream'.",&tolua_err);
 return 0;
#endif
}

/* method: appendStream of class  PmtSection */
static int tolua_mpeg2_PmtSection_appendStream01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PmtSection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PmtSection::Stream",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PmtSection* self = (PmtSection*)  tolua_tousertype(tolua_S,1,0);
  PmtSection::Stream* stream = ((PmtSection::Stream*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendStream'",NULL);
#endif
 {
  self->appendStream(*stream);
 }
 }
 return 0;
tolua_lerror:
 return tolua_mpeg2_PmtSection_appendStream00(tolua_S);
}

/* get function: TAG of class  ApplicationSignallingDescriptor */
static int tolua_get_ApplicationSignallingDescriptor_TAG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)ApplicationSignallingDescriptor::TAG);
 return 1;
}

/* method: new of class  ApplicationSignallingDescriptor */
static int tolua_mpeg2_ApplicationSignallingDescriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ApplicationSignallingDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ApplicationSignallingDescriptor* tolua_ret = (ApplicationSignallingDescriptor*)  new ApplicationSignallingDescriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"ApplicationSignallingDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  ApplicationSignallingDescriptor */
static int tolua_mpeg2_ApplicationSignallingDescriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ApplicationSignallingDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ApplicationSignallingDescriptor* tolua_ret = (ApplicationSignallingDescriptor*)  new ApplicationSignallingDescriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"ApplicationSignallingDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: appendAppTypeAndAitVersion of class  ApplicationSignallingDescriptor */
static int tolua_mpeg2_ApplicationSignallingDescriptor_appendAppTypeAndAitVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ApplicationSignallingDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ApplicationSignallingDescriptor* self = (ApplicationSignallingDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned appType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned aitVersion = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendAppTypeAndAitVersion'",NULL);
#endif
 {
  self->appendAppTypeAndAitVersion(appType,aitVersion);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendAppTypeAndAitVersion'.",&tolua_err);
 return 0;
#endif
}

/* get function: TAG of class  AssociationTagDescriptor */
static int tolua_get_AssociationTagDescriptor_TAG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)AssociationTagDescriptor::TAG);
 return 1;
}

/* method: new of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  AssociationTagDescriptor* tolua_ret = (AssociationTagDescriptor*)  new AssociationTagDescriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"AssociationTagDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  AssociationTagDescriptor* tolua_ret = (AssociationTagDescriptor*)  new AssociationTagDescriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"AssociationTagDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getAssociationTag of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getAssociationTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAssociationTag'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getAssociationTag();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssociationTag'.",&tolua_err);
 return 0;
#endif
}

/* method: getUse of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUse'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getUse();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUse'.",&tolua_err);
 return 0;
#endif
}

/* method: getSelectorLength of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getSelectorLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelectorLength'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getSelectorLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelectorLength'.",&tolua_err);
 return 0;
#endif
}

/* method: getSelector of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getSelector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned selectorLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelector'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getSelector(selectorLength);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)selectorLength);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelector'.",&tolua_err);
 return 0;
#endif
}

/* method: hasTransactionId of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_hasTransactionId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasTransactionId'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasTransactionId();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasTransactionId'.",&tolua_err);
 return 0;
#endif
}

/* method: getTransactionId of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getTransactionId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransactionId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTransactionId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransactionId'.",&tolua_err);
 return 0;
#endif
}

/* method: hasTimeout of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_hasTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasTimeout'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasTimeout();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasTimeout'.",&tolua_err);
 return 0;
#endif
}

/* method: getTimeout of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTimeout'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getTimeout();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTimeout'.",&tolua_err);
 return 0;
#endif
}

/* method: getPrivateData of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_getPrivateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AssociationTagDescriptor* self = (const AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned privateDataLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPrivateData'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getPrivateData(privateDataLength);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)privateDataLength);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPrivateData'.",&tolua_err);
 return 0;
#endif
}

/* method: setAssociationTag of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setAssociationTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned tag = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAssociationTag'",NULL);
#endif
 {
  self->setAssociationTag(tag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAssociationTag'.",&tolua_err);
 return 0;
#endif
}

/* method: setUse of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned use = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUse'",NULL);
#endif
 {
  self->setUse(use);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUse'.",&tolua_err);
 return 0;
#endif
}

/* method: setSelectorLength of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setSelectorLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelectorLength'",NULL);
#endif
 {
  self->setSelectorLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelectorLength'.",&tolua_err);
 return 0;
#endif
}

/* method: setSelector of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setSelector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* selector = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned selectorLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelector'",NULL);
#endif
 {
  self->setSelector(selector,selectorLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelector'.",&tolua_err);
 return 0;
#endif
}

/* method: setTransactionId of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setTransactionId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransactionId'",NULL);
#endif
 {
  self->setTransactionId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransactionId'.",&tolua_err);
 return 0;
#endif
}

/* method: setTimeout of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned timeout = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTimeout'",NULL);
#endif
 {
  self->setTimeout(timeout);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTimeout'.",&tolua_err);
 return 0;
#endif
}

/* method: setPrivateData of class  AssociationTagDescriptor */
static int tolua_mpeg2_AssociationTagDescriptor_setPrivateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AssociationTagDescriptor",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AssociationTagDescriptor* self = (AssociationTagDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* privateData = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned privateDataLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPrivateData'",NULL);
#endif
 {
  self->setPrivateData(privateData,privateDataLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPrivateData'.",&tolua_err);
 return 0;
#endif
}

/* get function: TAG of class  CarouselIdentifierDescriptor */
static int tolua_get_CarouselIdentifierDescriptor_TAG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CarouselIdentifierDescriptor::TAG);
 return 1;
}

/* method: new of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CarouselIdentifierDescriptor* tolua_ret = (CarouselIdentifierDescriptor*)  new CarouselIdentifierDescriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CarouselIdentifierDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CarouselIdentifierDescriptor* tolua_ret = (CarouselIdentifierDescriptor*)  new CarouselIdentifierDescriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"CarouselIdentifierDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getCarouselId of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_getCarouselId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CarouselIdentifierDescriptor* self = (const CarouselIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCarouselId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getCarouselId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCarouselId'.",&tolua_err);
 return 0;
#endif
}

/* method: getFormatId of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_getFormatId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CarouselIdentifierDescriptor* self = (const CarouselIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFormatId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getFormatId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFormatId'.",&tolua_err);
 return 0;
#endif
}

/* method: setCarouselId of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_setCarouselId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CarouselIdentifierDescriptor* self = (const CarouselIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCarouselId'",NULL);
#endif
 {
  self->setCarouselId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCarouselId'.",&tolua_err);
 return 0;
#endif
}

/* method: setFormatId of class  CarouselIdentifierDescriptor */
static int tolua_mpeg2_CarouselIdentifierDescriptor_setFormatId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CarouselIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CarouselIdentifierDescriptor* self = (const CarouselIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFormatId'",NULL);
#endif
 {
  self->setFormatId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFormatId'.",&tolua_err);
 return 0;
#endif
}

/* get function: TAG of class  DataBroadcastIdDescriptor */
static int tolua_get_DataBroadcastIdDescriptor_TAG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DataBroadcastIdDescriptor::TAG);
 return 1;
}

/* method: new of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DataBroadcastIdDescriptor* tolua_ret = (DataBroadcastIdDescriptor*)  new DataBroadcastIdDescriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"DataBroadcastIdDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DataBroadcastIdDescriptor* tolua_ret = (DataBroadcastIdDescriptor*)  new DataBroadcastIdDescriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"DataBroadcastIdDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getDataBroadcastId of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_getDataBroadcastId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DataBroadcastIdDescriptor* self = (const DataBroadcastIdDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDataBroadcastId'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getDataBroadcastId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDataBroadcastId'.",&tolua_err);
 return 0;
#endif
}

/* method: getSelectorBytes of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_getSelectorBytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DataBroadcastIdDescriptor* self = (const DataBroadcastIdDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned selectorLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelectorBytes'",NULL);
#endif
 {
  unsigned char* tolua_ret = (unsigned char*)  self->getSelectorBytes(selectorLength);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)selectorLength);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelectorBytes'.",&tolua_err);
 return 0;
#endif
}

/* method: setDataBroadcastId of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_setDataBroadcastId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DataBroadcastIdDescriptor* self = (DataBroadcastIdDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDataBroadcastId'",NULL);
#endif
 {
  self->setDataBroadcastId(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDataBroadcastId'.",&tolua_err);
 return 0;
#endif
}

/* method: setSelectorBytes of class  DataBroadcastIdDescriptor */
static int tolua_mpeg2_DataBroadcastIdDescriptor_setSelectorBytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DataBroadcastIdDescriptor",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DataBroadcastIdDescriptor* self = (DataBroadcastIdDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* selectorBytes = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned selectorLength = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelectorBytes'",NULL);
#endif
 {
  self->setSelectorBytes(selectorBytes,selectorLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelectorBytes'.",&tolua_err);
 return 0;
#endif
}

/* get function: TAG of class  StreamIdentifierDescriptor */
static int tolua_get_StreamIdentifierDescriptor_TAG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)StreamIdentifierDescriptor::TAG);
 return 1;
}

/* method: new of class  StreamIdentifierDescriptor */
static int tolua_mpeg2_StreamIdentifierDescriptor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StreamIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  StreamIdentifierDescriptor* tolua_ret = (StreamIdentifierDescriptor*)  new StreamIdentifierDescriptor();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"StreamIdentifierDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  StreamIdentifierDescriptor */
static int tolua_mpeg2_StreamIdentifierDescriptor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"StreamIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  StreamIdentifierDescriptor* tolua_ret = (StreamIdentifierDescriptor*)  new StreamIdentifierDescriptor();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"StreamIdentifierDescriptor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getComponentTag of class  StreamIdentifierDescriptor */
static int tolua_mpeg2_StreamIdentifierDescriptor_getComponentTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StreamIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StreamIdentifierDescriptor* self = (const StreamIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getComponentTag'",NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->getComponentTag();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getComponentTag'.",&tolua_err);
 return 0;
#endif
}

/* method: setComponentTag of class  StreamIdentifierDescriptor */
static int tolua_mpeg2_StreamIdentifierDescriptor_setComponentTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StreamIdentifierDescriptor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StreamIdentifierDescriptor* self = (StreamIdentifierDescriptor*)  tolua_tousertype(tolua_S,1,0);
  unsigned tag = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setComponentTag'",NULL);
#endif
 {
  self->setComponentTag(tag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setComponentTag'.",&tolua_err);
 return 0;
#endif
}

/* Open function */
TOLUA_API int tolua_mpeg2_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Chunk","Chunk","",tolua_collect_Chunk);
#else
 tolua_cclass(tolua_S,"Chunk","Chunk","",NULL);
#endif
 tolua_beginmodule(tolua_S,"Chunk");
 tolua_function(tolua_S,"new",tolua_mpeg2_Chunk_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_Chunk_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_Chunk_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_Chunk_delete00);
 tolua_function(tolua_S,"getData",tolua_mpeg2_Chunk_getData00);
 tolua_function(tolua_S,"isAllocated",tolua_mpeg2_Chunk_isAllocated00);
 tolua_function(tolua_S,"setData",tolua_mpeg2_Chunk_setData00);
 tolua_function(tolua_S,"getDataLength",tolua_mpeg2_Chunk_getDataLength00);
 tolua_function(tolua_S,"finalize",tolua_mpeg2_Chunk_finalize00);
 tolua_function(tolua_S,"verify",tolua_mpeg2_Chunk_verify00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"DescriptorIterator","Iterator<Descriptor>","<Descriptor>",tolua_collect_Iterator_Descriptor_);
#else
 tolua_cclass(tolua_S,"DescriptorIterator","Iterator<Descriptor>","<Descriptor>",NULL);
#endif
 tolua_beginmodule(tolua_S,"DescriptorIterator");
 tolua_function(tolua_S,"delete",tolua_mpeg2_DescriptorIterator_delete00);
 tolua_function(tolua_S,"hasNext",tolua_mpeg2_DescriptorIterator_hasNext00);
 tolua_function(tolua_S,"getNext",tolua_mpeg2_DescriptorIterator_getNext00);
 tolua_function(tolua_S,"getNextLength",tolua_mpeg2_DescriptorIterator_getNextLength00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"ProgramIterator","Iterator<PatSection::Program>","<PatSection::Program>",tolua_collect_Iterator_PatSection__Program_);
#else
 tolua_cclass(tolua_S,"ProgramIterator","Iterator<PatSection::Program>","<PatSection::Program>",NULL);
#endif
 tolua_beginmodule(tolua_S,"ProgramIterator");
 tolua_function(tolua_S,"delete",tolua_mpeg2_ProgramIterator_delete00);
 tolua_function(tolua_S,"hasNext",tolua_mpeg2_ProgramIterator_hasNext00);
 tolua_function(tolua_S,"getNext",tolua_mpeg2_ProgramIterator_getNext00);
 tolua_function(tolua_S,"getNextLength",tolua_mpeg2_ProgramIterator_getNextLength00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"StreamIterator","Iterator<PmtSection::Stream>","<PmtSection::Stream>",tolua_collect_Iterator_PmtSection__Stream_);
#else
 tolua_cclass(tolua_S,"StreamIterator","Iterator<PmtSection::Stream>","<PmtSection::Stream>",NULL);
#endif
 tolua_beginmodule(tolua_S,"StreamIterator");
 tolua_function(tolua_S,"delete",tolua_mpeg2_StreamIterator_delete00);
 tolua_function(tolua_S,"hasNext",tolua_mpeg2_StreamIterator_hasNext00);
 tolua_function(tolua_S,"getNext",tolua_mpeg2_StreamIterator_getNext00);
 tolua_function(tolua_S,"getNextLength",tolua_mpeg2_StreamIterator_getNextLength00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"AFC_RESERVED",AFC_RESERVED);
 tolua_constant(tolua_S,"AFC_ONLY_PAYLOAD",AFC_ONLY_PAYLOAD);
 tolua_constant(tolua_S,"AFC_ONLY_ADAPT_FIELD",AFC_ONLY_ADAPT_FIELD);
 tolua_constant(tolua_S,"AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD",AFC_BOTH_PAYLOAD_AND_ADAPT_FIELD);
 tolua_constant(tolua_S,"SC_NOT_SCRAMBLED",SC_NOT_SCRAMBLED);
 tolua_constant(tolua_S,"SC_USER_DEFINED_1",SC_USER_DEFINED_1);
 tolua_constant(tolua_S,"SC_USER_DEFINED_2",SC_USER_DEFINED_2);
 tolua_constant(tolua_S,"SC_USER_DEFINED_3",SC_USER_DEFINED_3);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TSPacket","TSPacket","Chunk",tolua_collect_TSPacket);
#else
 tolua_cclass(tolua_S,"TSPacket","TSPacket","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"TSPacket");
 tolua_variable(tolua_S,"PACKET_SIZE",tolua_get_TSPacket_PACKET_SIZE,NULL);
 tolua_variable(tolua_S,"MAX_PAYLOAD_SIZE",tolua_get_TSPacket_MAX_PAYLOAD_SIZE,NULL);
 tolua_variable(tolua_S,"STUFFING_BYTE",tolua_get_TSPacket_STUFFING_BYTE,NULL);
 tolua_variable(tolua_S,"SYNC_BYTE",tolua_get_TSPacket_SYNC_BYTE,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_TSPacket_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_TSPacket_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_TSPacket_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_TSPacket_delete00);
 tolua_function(tolua_S,"getSyncByte",tolua_mpeg2_TSPacket_getSyncByte00);
 tolua_function(tolua_S,"getTransportErrorIndicator",tolua_mpeg2_TSPacket_getTransportErrorIndicator00);
 tolua_function(tolua_S,"getPayloadUnitStartIndicator",tolua_mpeg2_TSPacket_getPayloadUnitStartIndicator00);
 tolua_function(tolua_S,"getTransportPriority",tolua_mpeg2_TSPacket_getTransportPriority00);
 tolua_function(tolua_S,"getPid",tolua_mpeg2_TSPacket_getPid00);
 tolua_function(tolua_S,"getTransportScramblingControl",tolua_mpeg2_TSPacket_getTransportScramblingControl00);
 tolua_function(tolua_S,"getAdaptationFieldControl",tolua_mpeg2_TSPacket_getAdaptationFieldControl00);
 tolua_function(tolua_S,"getContinuityCounter",tolua_mpeg2_TSPacket_getContinuityCounter00);
 tolua_function(tolua_S,"hasAdaptationField",tolua_mpeg2_TSPacket_hasAdaptationField00);
 tolua_function(tolua_S,"getAdaptationFieldLength",tolua_mpeg2_TSPacket_getAdaptationFieldLength00);
 tolua_function(tolua_S,"getDiscontinuityIndicator",tolua_mpeg2_TSPacket_getDiscontinuityIndicator00);
 tolua_function(tolua_S,"getRandomAccessIndicator",tolua_mpeg2_TSPacket_getRandomAccessIndicator00);
 tolua_function(tolua_S,"getElementaryStreamPriorityIndicator",tolua_mpeg2_TSPacket_getElementaryStreamPriorityIndicator00);
 tolua_function(tolua_S,"getPcrFlag",tolua_mpeg2_TSPacket_getPcrFlag00);
 tolua_function(tolua_S,"getOpcrFlag",tolua_mpeg2_TSPacket_getOpcrFlag00);
 tolua_function(tolua_S,"getSplicingPointFlag",tolua_mpeg2_TSPacket_getSplicingPointFlag00);
 tolua_function(tolua_S,"getTransportPrivateDataFlag",tolua_mpeg2_TSPacket_getTransportPrivateDataFlag00);
 tolua_function(tolua_S,"getAdaptationFieldExtensionFlag",tolua_mpeg2_TSPacket_getAdaptationFieldExtensionFlag00);
 tolua_function(tolua_S,"hasPcr",tolua_mpeg2_TSPacket_hasPcr00);
 tolua_function(tolua_S,"getPcrBase",tolua_mpeg2_TSPacket_getPcrBase00);
 tolua_function(tolua_S,"getPcrExtension",tolua_mpeg2_TSPacket_getPcrExtension00);
 tolua_function(tolua_S,"hasOriginalPcr",tolua_mpeg2_TSPacket_hasOriginalPcr00);
 tolua_function(tolua_S,"getOriginalPcrBase",tolua_mpeg2_TSPacket_getOriginalPcrBase00);
 tolua_function(tolua_S,"getOriginalPcrExtension",tolua_mpeg2_TSPacket_getOriginalPcrExtension00);
 tolua_function(tolua_S,"hasSpliceCountdown",tolua_mpeg2_TSPacket_hasSpliceCountdown00);
 tolua_function(tolua_S,"getSpliceCountdown",tolua_mpeg2_TSPacket_getSpliceCountdown00);
 tolua_function(tolua_S,"hasTransportPrivateData",tolua_mpeg2_TSPacket_hasTransportPrivateData00);
 tolua_function(tolua_S,"getTransportPrivateDataLength",tolua_mpeg2_TSPacket_getTransportPrivateDataLength00);
 tolua_function(tolua_S,"getTransportDataBytes",tolua_mpeg2_TSPacket_getTransportDataBytes00);
 tolua_function(tolua_S,"hasAdaptationFieldExtension",tolua_mpeg2_TSPacket_hasAdaptationFieldExtension00);
 tolua_function(tolua_S,"getAdaptationFieldExtensionLength",tolua_mpeg2_TSPacket_getAdaptationFieldExtensionLength00);
 tolua_function(tolua_S,"getLtwFlag",tolua_mpeg2_TSPacket_getLtwFlag00);
 tolua_function(tolua_S,"getPiecewiseRateFlag",tolua_mpeg2_TSPacket_getPiecewiseRateFlag00);
 tolua_function(tolua_S,"getSeamlessSpliceFlag",tolua_mpeg2_TSPacket_getSeamlessSpliceFlag00);
 tolua_function(tolua_S,"hasLtw",tolua_mpeg2_TSPacket_hasLtw00);
 tolua_function(tolua_S,"getLtwValidFlag",tolua_mpeg2_TSPacket_getLtwValidFlag00);
 tolua_function(tolua_S,"getLtwOffset",tolua_mpeg2_TSPacket_getLtwOffset00);
 tolua_function(tolua_S,"hasPiecewiseRate",tolua_mpeg2_TSPacket_hasPiecewiseRate00);
 tolua_function(tolua_S,"getPiecewiseRate",tolua_mpeg2_TSPacket_getPiecewiseRate00);
 tolua_function(tolua_S,"hasSeamlessSplice",tolua_mpeg2_TSPacket_hasSeamlessSplice00);
 tolua_function(tolua_S,"getSpliceType",tolua_mpeg2_TSPacket_getSpliceType00);
 tolua_function(tolua_S,"getDtsNextAu",tolua_mpeg2_TSPacket_getDtsNextAu00);
 tolua_function(tolua_S,"getPayloadLength",tolua_mpeg2_TSPacket_getPayloadLength00);
 tolua_function(tolua_S,"getPayload",tolua_mpeg2_TSPacket_getPayload00);
 tolua_function(tolua_S,"getPayload",tolua_mpeg2_TSPacket_getPayload01);
 tolua_function(tolua_S,"setTransportErrorIndicator",tolua_mpeg2_TSPacket_setTransportErrorIndicator00);
 tolua_function(tolua_S,"setPayloadUnitStartIndicator",tolua_mpeg2_TSPacket_setPayloadUnitStartIndicator00);
 tolua_function(tolua_S,"setTransportPriority",tolua_mpeg2_TSPacket_setTransportPriority00);
 tolua_function(tolua_S,"setPid",tolua_mpeg2_TSPacket_setPid00);
 tolua_function(tolua_S,"setTransportScramblingControl",tolua_mpeg2_TSPacket_setTransportScramblingControl00);
 tolua_function(tolua_S,"setAdaptationFieldControl",tolua_mpeg2_TSPacket_setAdaptationFieldControl00);
 tolua_function(tolua_S,"setContinuityCounter",tolua_mpeg2_TSPacket_setContinuityCounter00);
 tolua_function(tolua_S,"incContinuityCounter",tolua_mpeg2_TSPacket_incContinuityCounter00);
 tolua_function(tolua_S,"setAdaptationFieldLength",tolua_mpeg2_TSPacket_setAdaptationFieldLength00);
 tolua_function(tolua_S,"setDiscontinuityIndicator",tolua_mpeg2_TSPacket_setDiscontinuityIndicator00);
 tolua_function(tolua_S,"setRandomAccessIndicator",tolua_mpeg2_TSPacket_setRandomAccessIndicator00);
 tolua_function(tolua_S,"setElementaryStreamPriorityIndicator",tolua_mpeg2_TSPacket_setElementaryStreamPriorityIndicator00);
 tolua_function(tolua_S,"setPcrFlag",tolua_mpeg2_TSPacket_setPcrFlag00);
 tolua_function(tolua_S,"setOpcrFlag",tolua_mpeg2_TSPacket_setOpcrFlag00);
 tolua_function(tolua_S,"setSplicingPointFlag",tolua_mpeg2_TSPacket_setSplicingPointFlag00);
 tolua_function(tolua_S,"setTransportPrivateDataFlag",tolua_mpeg2_TSPacket_setTransportPrivateDataFlag00);
 tolua_function(tolua_S,"setAdaptationFieldExtensionFlag",tolua_mpeg2_TSPacket_setAdaptationFieldExtensionFlag00);
 tolua_function(tolua_S,"setPcrBase",tolua_mpeg2_TSPacket_setPcrBase00);
 tolua_function(tolua_S,"setPcrExtension",tolua_mpeg2_TSPacket_setPcrExtension00);
 tolua_function(tolua_S,"setOriginalPcrBase",tolua_mpeg2_TSPacket_setOriginalPcrBase00);
 tolua_function(tolua_S,"setOriginalPcrExtension",tolua_mpeg2_TSPacket_setOriginalPcrExtension00);
 tolua_function(tolua_S,"setSpliceCountdown",tolua_mpeg2_TSPacket_setSpliceCountdown00);
 tolua_function(tolua_S,"setTransportPrivateDataLength",tolua_mpeg2_TSPacket_setTransportPrivateDataLength00);
 tolua_function(tolua_S,"setTransportDataBytes",tolua_mpeg2_TSPacket_setTransportDataBytes00);
 tolua_function(tolua_S,"setAdaptationFieldExtensionLength",tolua_mpeg2_TSPacket_setAdaptationFieldExtensionLength00);
 tolua_function(tolua_S,"setLtwFlag",tolua_mpeg2_TSPacket_setLtwFlag00);
 tolua_function(tolua_S,"setPiecewiseRateFlag",tolua_mpeg2_TSPacket_setPiecewiseRateFlag00);
 tolua_function(tolua_S,"setSeamlessSpliceFlag",tolua_mpeg2_TSPacket_setSeamlessSpliceFlag00);
 tolua_function(tolua_S,"setLtwValidFlag",tolua_mpeg2_TSPacket_setLtwValidFlag00);
 tolua_function(tolua_S,"setLtwOffset",tolua_mpeg2_TSPacket_setLtwOffset00);
 tolua_function(tolua_S,"setPiecewiseRate",tolua_mpeg2_TSPacket_setPiecewiseRate00);
 tolua_function(tolua_S,"setSpliceType",tolua_mpeg2_TSPacket_setSpliceType00);
 tolua_function(tolua_S,"setDtsNextAu",tolua_mpeg2_TSPacket_setDtsNextAu00);
 tolua_function(tolua_S,"setPayload",tolua_mpeg2_TSPacket_setPayload00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"PROGRAM_STREAM_MAP",PROGRAM_STREAM_MAP);
 tolua_constant(tolua_S,"PRIVATE_STREAM_1",PRIVATE_STREAM_1);
 tolua_constant(tolua_S,"PADDING_STREAM",PADDING_STREAM);
 tolua_constant(tolua_S,"PRIVATE_STREAM_2",PRIVATE_STREAM_2);
 tolua_constant(tolua_S,"ECM_STREAM",ECM_STREAM);
 tolua_constant(tolua_S,"EMM_STREAM",EMM_STREAM);
 tolua_constant(tolua_S,"PROGRAM_STREAM_DIRECTORY",PROGRAM_STREAM_DIRECTORY);
 tolua_constant(tolua_S,"DSMCC_STREAM",DSMCC_STREAM);
 tolua_constant(tolua_S,"ITU_T_REC_H_222_1_TYPE_E_STREAM",ITU_T_REC_H_222_1_TYPE_E_STREAM);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PesPacket","PesPacket","Chunk",tolua_collect_PesPacket);
#else
 tolua_cclass(tolua_S,"PesPacket","PesPacket","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"PesPacket");
 tolua_function(tolua_S,"new",tolua_mpeg2_PesPacket_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PesPacket_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PesPacket_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_PesPacket_delete00);
 tolua_function(tolua_S,"getPacketStartCodePrefix",tolua_mpeg2_PesPacket_getPacketStartCodePrefix00);
 tolua_function(tolua_S,"getStreamId",tolua_mpeg2_PesPacket_getStreamId00);
 tolua_function(tolua_S,"getPesPacketLength",tolua_mpeg2_PesPacket_getPesPacketLength00);
 tolua_function(tolua_S,"getPesScramblingControl",tolua_mpeg2_PesPacket_getPesScramblingControl00);
 tolua_function(tolua_S,"getPesPriority",tolua_mpeg2_PesPacket_getPesPriority00);
 tolua_function(tolua_S,"getDataAlignmentIndicator",tolua_mpeg2_PesPacket_getDataAlignmentIndicator00);
 tolua_function(tolua_S,"getCopyright",tolua_mpeg2_PesPacket_getCopyright00);
 tolua_function(tolua_S,"getOriginalOrCopy",tolua_mpeg2_PesPacket_getOriginalOrCopy00);
 tolua_function(tolua_S,"getPtsDtsFlags",tolua_mpeg2_PesPacket_getPtsDtsFlags00);
 tolua_function(tolua_S,"getEscrFlag",tolua_mpeg2_PesPacket_getEscrFlag00);
 tolua_function(tolua_S,"getEsRateFlag",tolua_mpeg2_PesPacket_getEsRateFlag00);
 tolua_function(tolua_S,"getDsmTrickModeFlag",tolua_mpeg2_PesPacket_getDsmTrickModeFlag00);
 tolua_function(tolua_S,"getAdditionalCopyInfoFlag",tolua_mpeg2_PesPacket_getAdditionalCopyInfoFlag00);
 tolua_function(tolua_S,"getPesCrcFlag",tolua_mpeg2_PesPacket_getPesCrcFlag00);
 tolua_function(tolua_S,"getPesExtensionFlag",tolua_mpeg2_PesPacket_getPesExtensionFlag00);
 tolua_function(tolua_S,"getPesHeaderDataLength",tolua_mpeg2_PesPacket_getPesHeaderDataLength00);
 tolua_function(tolua_S,"hasPts",tolua_mpeg2_PesPacket_hasPts00);
 tolua_function(tolua_S,"getPts",tolua_mpeg2_PesPacket_getPts00);
 tolua_function(tolua_S,"hasDts",tolua_mpeg2_PesPacket_hasDts00);
 tolua_function(tolua_S,"getDts",tolua_mpeg2_PesPacket_getDts00);
 tolua_function(tolua_S,"hasEscr",tolua_mpeg2_PesPacket_hasEscr00);
 tolua_function(tolua_S,"getEscrBase",tolua_mpeg2_PesPacket_getEscrBase00);
 tolua_function(tolua_S,"getEscrExtension",tolua_mpeg2_PesPacket_getEscrExtension00);
 tolua_function(tolua_S,"verify",tolua_mpeg2_PesPacket_verify00);
 tolua_function(tolua_S,"setPacketStartCodePrefix",tolua_mpeg2_PesPacket_setPacketStartCodePrefix00);
 tolua_function(tolua_S,"setStreamId",tolua_mpeg2_PesPacket_setStreamId00);
 tolua_function(tolua_S,"setPesPacketLength",tolua_mpeg2_PesPacket_setPesPacketLength00);
 tolua_function(tolua_S,"finalize",tolua_mpeg2_PesPacket_finalize00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Descriptor","Descriptor","Chunk",tolua_collect_Descriptor);
#else
 tolua_cclass(tolua_S,"Descriptor","Descriptor","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"Descriptor");
 tolua_variable(tolua_S,"MAX_LENGTH",tolua_get_Descriptor_MAX_LENGTH,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_Descriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_Descriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_Descriptor_new00_local);
 tolua_function(tolua_S,"new",tolua_mpeg2_Descriptor_new01);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_Descriptor_new01_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_Descriptor_new01_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_Descriptor_delete00);
 tolua_function(tolua_S,"getDescriptorTag",tolua_mpeg2_Descriptor_getDescriptorTag00);
 tolua_function(tolua_S,"getDescriptorLength",tolua_mpeg2_Descriptor_getDescriptorLength00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Section","Section","Chunk",tolua_collect_Section);
#else
 tolua_cclass(tolua_S,"Section","Section","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"Section");
 tolua_function(tolua_S,"new",tolua_mpeg2_Section_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_Section_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_Section_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_Section_delete00);
 tolua_function(tolua_S,"getTableId",tolua_mpeg2_Section_getTableId00);
 tolua_function(tolua_S,"getSectionSyntaxIndicator",tolua_mpeg2_Section_getSectionSyntaxIndicator00);
 tolua_function(tolua_S,"getPrivateIndicator",tolua_mpeg2_Section_getPrivateIndicator00);
 tolua_function(tolua_S,"getSectionLength",tolua_mpeg2_Section_getSectionLength00);
 tolua_function(tolua_S,"setSectionLength",tolua_mpeg2_Section_setSectionLength00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PsiSection","PsiSection","Section",tolua_collect_PsiSection);
#else
 tolua_cclass(tolua_S,"PsiSection","PsiSection","Section",NULL);
#endif
 tolua_beginmodule(tolua_S,"PsiSection");
 tolua_function(tolua_S,"new",tolua_mpeg2_PsiSection_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PsiSection_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PsiSection_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_PsiSection_delete00);
 tolua_function(tolua_S,"getTableIdExtension",tolua_mpeg2_PsiSection_getTableIdExtension00);
 tolua_function(tolua_S,"getVersionNumber",tolua_mpeg2_PsiSection_getVersionNumber00);
 tolua_function(tolua_S,"getCurrentNextIndicator",tolua_mpeg2_PsiSection_getCurrentNextIndicator00);
 tolua_function(tolua_S,"getSectionNumber",tolua_mpeg2_PsiSection_getSectionNumber00);
 tolua_function(tolua_S,"getLastSectionNumber",tolua_mpeg2_PsiSection_getLastSectionNumber00);
 tolua_function(tolua_S,"getCrc32",tolua_mpeg2_PsiSection_getCrc3200);
 tolua_function(tolua_S,"setTableIdExtension",tolua_mpeg2_PsiSection_setTableIdExtension00);
 tolua_function(tolua_S,"setVersionNumber",tolua_mpeg2_PsiSection_setVersionNumber00);
 tolua_function(tolua_S,"setCurrentNextIndicator",tolua_mpeg2_PsiSection_setCurrentNextIndicator00);
 tolua_function(tolua_S,"setSectionNumber",tolua_mpeg2_PsiSection_setSectionNumber00);
 tolua_function(tolua_S,"setLastSectionNumber",tolua_mpeg2_PsiSection_setLastSectionNumber00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PatSection","PatSection","PsiSection",tolua_collect_PatSection);
#else
 tolua_cclass(tolua_S,"PatSection","PatSection","PsiSection",NULL);
#endif
 tolua_beginmodule(tolua_S,"PatSection");
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Program","PatSection::Program","Chunk",tolua_collect_PatSection__Program);
#else
 tolua_cclass(tolua_S,"Program","PatSection::Program","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"Program");
 tolua_function(tolua_S,"new",tolua_mpeg2_PatSection_Program_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PatSection_Program_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PatSection_Program_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_PatSection_Program_delete00);
 tolua_function(tolua_S,"getProgramNumber",tolua_mpeg2_PatSection_Program_getProgramNumber00);
 tolua_function(tolua_S,"getPid",tolua_mpeg2_PatSection_Program_getPid00);
 tolua_function(tolua_S,"setProgramNumber",tolua_mpeg2_PatSection_Program_setProgramNumber00);
 tolua_function(tolua_S,"setPid",tolua_mpeg2_PatSection_Program_setPid00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"new",tolua_mpeg2_PatSection_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PatSection_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PatSection_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_PatSection_delete00);
 tolua_function(tolua_S,"getProgramsIterator",tolua_mpeg2_PatSection_getProgramsIterator00);
 tolua_function(tolua_S,"getTransportStreamId",tolua_mpeg2_PatSection_getTransportStreamId00);
 tolua_function(tolua_S,"setTransportStreamId",tolua_mpeg2_PatSection_setTransportStreamId00);
 tolua_function(tolua_S,"appendProgram",tolua_mpeg2_PatSection_appendProgram00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PmtSection","PmtSection","PsiSection",tolua_collect_PmtSection);
#else
 tolua_cclass(tolua_S,"PmtSection","PmtSection","PsiSection",NULL);
#endif
 tolua_beginmodule(tolua_S,"PmtSection");
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Stream","PmtSection::Stream","Chunk",tolua_collect_PmtSection__Stream);
#else
 tolua_cclass(tolua_S,"Stream","PmtSection::Stream","Chunk",NULL);
#endif
 tolua_beginmodule(tolua_S,"Stream");
 tolua_function(tolua_S,"new",tolua_mpeg2_PmtSection_Stream_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PmtSection_Stream_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PmtSection_Stream_new00_local);
 tolua_function(tolua_S,"getStreamType",tolua_mpeg2_PmtSection_Stream_getStreamType00);
 tolua_function(tolua_S,"getElementaryPid",tolua_mpeg2_PmtSection_Stream_getElementaryPid00);
 tolua_function(tolua_S,"getEsInfoLength",tolua_mpeg2_PmtSection_Stream_getEsInfoLength00);
 tolua_function(tolua_S,"getDescriptorsIterator",tolua_mpeg2_PmtSection_Stream_getDescriptorsIterator00);
 tolua_function(tolua_S,"setStreamType",tolua_mpeg2_PmtSection_Stream_setStreamType00);
 tolua_function(tolua_S,"setElementaryPid",tolua_mpeg2_PmtSection_Stream_setElementaryPid00);
 tolua_function(tolua_S,"setEsInfoLength",tolua_mpeg2_PmtSection_Stream_setEsInfoLength00);
 tolua_function(tolua_S,"appendDescriptor",tolua_mpeg2_PmtSection_Stream_appendDescriptor00);
 tolua_function(tolua_S,"appendDescriptor",tolua_mpeg2_PmtSection_Stream_appendDescriptor01);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"new",tolua_mpeg2_PmtSection_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_PmtSection_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_PmtSection_new00_local);
 tolua_function(tolua_S,"getProgramNumber",tolua_mpeg2_PmtSection_getProgramNumber00);
 tolua_function(tolua_S,"getPcrPid",tolua_mpeg2_PmtSection_getPcrPid00);
 tolua_function(tolua_S,"getProgramInfoLength",tolua_mpeg2_PmtSection_getProgramInfoLength00);
 tolua_function(tolua_S,"getDescriptorsIterator",tolua_mpeg2_PmtSection_getDescriptorsIterator00);
 tolua_function(tolua_S,"getStreamsIterator",tolua_mpeg2_PmtSection_getStreamsIterator00);
 tolua_function(tolua_S,"setProgramNumber",tolua_mpeg2_PmtSection_setProgramNumber00);
 tolua_function(tolua_S,"setPcrPid",tolua_mpeg2_PmtSection_setPcrPid00);
 tolua_function(tolua_S,"setProgramInfoLength",tolua_mpeg2_PmtSection_setProgramInfoLength00);
 tolua_function(tolua_S,"appendDescriptor",tolua_mpeg2_PmtSection_appendDescriptor00);
 tolua_function(tolua_S,"appendStream",tolua_mpeg2_PmtSection_appendStream00);
 tolua_function(tolua_S,"appendStream",tolua_mpeg2_PmtSection_appendStream01);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"ApplicationSignallingDescriptor","ApplicationSignallingDescriptor","Descriptor",tolua_collect_ApplicationSignallingDescriptor);
#else
 tolua_cclass(tolua_S,"ApplicationSignallingDescriptor","ApplicationSignallingDescriptor","Descriptor",NULL);
#endif
 tolua_beginmodule(tolua_S,"ApplicationSignallingDescriptor");
 tolua_variable(tolua_S,"TAG",tolua_get_ApplicationSignallingDescriptor_TAG,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_ApplicationSignallingDescriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_ApplicationSignallingDescriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_ApplicationSignallingDescriptor_new00_local);
 tolua_function(tolua_S,"appendAppTypeAndAitVersion",tolua_mpeg2_ApplicationSignallingDescriptor_appendAppTypeAndAitVersion00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"AssociationTagDescriptor","AssociationTagDescriptor","Descriptor",tolua_collect_AssociationTagDescriptor);
#else
 tolua_cclass(tolua_S,"AssociationTagDescriptor","AssociationTagDescriptor","Descriptor",NULL);
#endif
 tolua_beginmodule(tolua_S,"AssociationTagDescriptor");
 tolua_variable(tolua_S,"TAG",tolua_get_AssociationTagDescriptor_TAG,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_AssociationTagDescriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_AssociationTagDescriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_AssociationTagDescriptor_new00_local);
 tolua_function(tolua_S,"delete",tolua_mpeg2_AssociationTagDescriptor_delete00);
 tolua_function(tolua_S,"getAssociationTag",tolua_mpeg2_AssociationTagDescriptor_getAssociationTag00);
 tolua_function(tolua_S,"getUse",tolua_mpeg2_AssociationTagDescriptor_getUse00);
 tolua_function(tolua_S,"getSelectorLength",tolua_mpeg2_AssociationTagDescriptor_getSelectorLength00);
 tolua_function(tolua_S,"getSelector",tolua_mpeg2_AssociationTagDescriptor_getSelector00);
 tolua_function(tolua_S,"hasTransactionId",tolua_mpeg2_AssociationTagDescriptor_hasTransactionId00);
 tolua_function(tolua_S,"getTransactionId",tolua_mpeg2_AssociationTagDescriptor_getTransactionId00);
 tolua_function(tolua_S,"hasTimeout",tolua_mpeg2_AssociationTagDescriptor_hasTimeout00);
 tolua_function(tolua_S,"getTimeout",tolua_mpeg2_AssociationTagDescriptor_getTimeout00);
 tolua_function(tolua_S,"getPrivateData",tolua_mpeg2_AssociationTagDescriptor_getPrivateData00);
 tolua_function(tolua_S,"setAssociationTag",tolua_mpeg2_AssociationTagDescriptor_setAssociationTag00);
 tolua_function(tolua_S,"setUse",tolua_mpeg2_AssociationTagDescriptor_setUse00);
 tolua_function(tolua_S,"setSelectorLength",tolua_mpeg2_AssociationTagDescriptor_setSelectorLength00);
 tolua_function(tolua_S,"setSelector",tolua_mpeg2_AssociationTagDescriptor_setSelector00);
 tolua_function(tolua_S,"setTransactionId",tolua_mpeg2_AssociationTagDescriptor_setTransactionId00);
 tolua_function(tolua_S,"setTimeout",tolua_mpeg2_AssociationTagDescriptor_setTimeout00);
 tolua_function(tolua_S,"setPrivateData",tolua_mpeg2_AssociationTagDescriptor_setPrivateData00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CarouselIdentifierDescriptor","CarouselIdentifierDescriptor","Descriptor",tolua_collect_CarouselIdentifierDescriptor);
#else
 tolua_cclass(tolua_S,"CarouselIdentifierDescriptor","CarouselIdentifierDescriptor","Descriptor",NULL);
#endif
 tolua_beginmodule(tolua_S,"CarouselIdentifierDescriptor");
 tolua_variable(tolua_S,"TAG",tolua_get_CarouselIdentifierDescriptor_TAG,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_CarouselIdentifierDescriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_CarouselIdentifierDescriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_CarouselIdentifierDescriptor_new00_local);
 tolua_function(tolua_S,"getCarouselId",tolua_mpeg2_CarouselIdentifierDescriptor_getCarouselId00);
 tolua_function(tolua_S,"getFormatId",tolua_mpeg2_CarouselIdentifierDescriptor_getFormatId00);
 tolua_function(tolua_S,"setCarouselId",tolua_mpeg2_CarouselIdentifierDescriptor_setCarouselId00);
 tolua_function(tolua_S,"setFormatId",tolua_mpeg2_CarouselIdentifierDescriptor_setFormatId00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"DataBroadcastIdDescriptor","DataBroadcastIdDescriptor","Descriptor",tolua_collect_DataBroadcastIdDescriptor);
#else
 tolua_cclass(tolua_S,"DataBroadcastIdDescriptor","DataBroadcastIdDescriptor","Descriptor",NULL);
#endif
 tolua_beginmodule(tolua_S,"DataBroadcastIdDescriptor");
 tolua_variable(tolua_S,"TAG",tolua_get_DataBroadcastIdDescriptor_TAG,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_DataBroadcastIdDescriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_DataBroadcastIdDescriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_DataBroadcastIdDescriptor_new00_local);
 tolua_function(tolua_S,"getDataBroadcastId",tolua_mpeg2_DataBroadcastIdDescriptor_getDataBroadcastId00);
 tolua_function(tolua_S,"getSelectorBytes",tolua_mpeg2_DataBroadcastIdDescriptor_getSelectorBytes00);
 tolua_function(tolua_S,"setDataBroadcastId",tolua_mpeg2_DataBroadcastIdDescriptor_setDataBroadcastId00);
 tolua_function(tolua_S,"setSelectorBytes",tolua_mpeg2_DataBroadcastIdDescriptor_setSelectorBytes00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"StreamIdentifierDescriptor","StreamIdentifierDescriptor","Descriptor",tolua_collect_StreamIdentifierDescriptor);
#else
 tolua_cclass(tolua_S,"StreamIdentifierDescriptor","StreamIdentifierDescriptor","Descriptor",NULL);
#endif
 tolua_beginmodule(tolua_S,"StreamIdentifierDescriptor");
 tolua_variable(tolua_S,"TAG",tolua_get_StreamIdentifierDescriptor_TAG,NULL);
 tolua_function(tolua_S,"new",tolua_mpeg2_StreamIdentifierDescriptor_new00);
 tolua_function(tolua_S,"new_local",tolua_mpeg2_StreamIdentifierDescriptor_new00_local);
 tolua_set_call_event(tolua_S,tolua_mpeg2_StreamIdentifierDescriptor_new00_local);
 tolua_function(tolua_S,"getComponentTag",tolua_mpeg2_StreamIdentifierDescriptor_getComponentTag00);
 tolua_function(tolua_S,"setComponentTag",tolua_mpeg2_StreamIdentifierDescriptor_setComponentTag00);
 tolua_endmodule(tolua_S);
 /*tolua_endmodule(tolua_S);*/ /* milano */
 return 1;
}
