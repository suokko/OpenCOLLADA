/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTFILTER_H__
#define __MayaDM_OBJECTFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ObjectFilter : public DependNode
{
public:
public:
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "objectFilter"){}
	virtual ~ObjectFilter(){}
	void setChild(bool ch)
	{
		if(ch == 0) return;
		fprintf(mFile,"setAttr \".ch\" %i;\n", ch);

	}
	void setInvert(bool inv)
	{
		if(inv == 0) return;
		fprintf(mFile,"setAttr \".inv\" %i;\n", inv);

	}
	void setAnnotation(const string& an)
	{
		if(an == "NULL") return;
		fprintf(mFile,"setAttr \".an\" -type \"string\" ");
		an.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCategory(const stringArray& cat)
	{
		fprintf(mFile,"setAttr \".cat\" -type \"stringArray\" ");
		cat.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisable(bool dis)
	{
		if(dis == 0) return;
		fprintf(mFile,"setAttr \".dis\" %i;\n", dis);

	}
	void setFilterClass(unsigned int fcls)
	{
		if(fcls == 0) return;
		fprintf(mFile,"setAttr \".fcls\" %i;\n", fcls);

	}
	void getChild()
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());

	}
	void getInvert()
	{
		fprintf(mFile,"\"%s.inv\"",mName.c_str());

	}
	void getInputList()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getOutputList()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
	void getAnnotation()
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());

	}
	void getCategory()
	{
		fprintf(mFile,"\"%s.cat\"",mName.c_str());

	}
	void getDisable()
	{
		fprintf(mFile,"\"%s.dis\"",mName.c_str());

	}
	void getFilterClass()
	{
		fprintf(mFile,"\"%s.fcls\"",mName.c_str());

	}
protected:
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTFILTER_H__