#include "ed_voice.h"
#include "SoraVoice.h"
#include "InitParam.h"

SVDECL void SVCALL Init(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || ip->sv) return;

	ip->sv = SoraVoice::CreateInstance(ip);
}

SVDECL void SVCALL End(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || !ip->sv) return;

	SoraVoice::DestoryInstance((SoraVoice*)ip->sv);
	ip->sv = nullptr;
}

SVDECL void SVCALL Play(void *v, void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!v || !p || !ip->sv) return;

	((SoraVoice*)ip->sv)->Play((const char*)v);
}

SVDECL void SVCALL Stop(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || !ip->sv) return;

	((SoraVoice *)ip->sv)->Stop();
}

SVDECL void SVCALL Input(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || !ip->sv) return;

	((SoraVoice *)ip->sv)->Input();
}

