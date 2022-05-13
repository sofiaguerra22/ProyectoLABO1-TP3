#include "Enum.h"

string OrganoToString(eOrgano organo)
{
	switch (organo)
	{
	case eOrgano::corazon:
		return "Corazon";
		break;
	case eOrgano::higado:
		return "Higado";
		break;
	case eOrgano::pancreas:
		return "Pancreas";
		break;
	case eOrgano::huesos:
		return "Huesos";
		break;
	case eOrgano::rinion:
		return "Rinion";
		break;
	case eOrgano::pulmones:
		return "Pulmones";
		break;
	case eOrgano::intestino:
		return "Intestino";
		break;
	case eOrgano::piel:
		return "Piel";
		break;
	case eOrgano::corneas:
		return "Corneas";
		break;
	default:
		return "";
		break;
	}
}

string TipoSangreToString(eTipoSangre sangre)
{
	switch (sangre)
	{
	case eTipoSangre::ON:
		return "O Negativo";
		break;
	case eTipoSangre::OP:
		return "O Positivo";
		break;
	case eTipoSangre::AN:
		return "A Negativo";
		break;
	case eTipoSangre::AP:
		return "A Positivo";
		break;
	case eTipoSangre::BN:
		return "B Negativo";
		break;
	case eTipoSangre::BP:
		return "B Positivo";
		break;
	case eTipoSangre::ABN:
		return "AB Negativo";
		break;
	case eTipoSangre::ABP:
		return "AB Positivo";
		break;
	default:
		return "";
		break;
	}
}

int OrganoToInt(eOrgano organo)
{
	switch (organo)
	{
	case eOrgano::corazon:
		return 0;
		break;
	case eOrgano::higado:
		return 1;
		break;
	case eOrgano::pancreas:
		return 2;
		break;
	case eOrgano::huesos:
		return 3;
		break;
	case eOrgano::rinion:
		return 4;
		break;
	case eOrgano::pulmones:
		return 5;
		break;
	case eOrgano::intestino:
		return 6;
		break;
	case eOrgano::piel:
		return 7;
		break;
	case eOrgano::corneas:
		return 8;
		break;
	default:
		return -1;
		break;
	}
}

