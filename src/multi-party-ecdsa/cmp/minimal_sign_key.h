

#ifndef SAFEHERON_MULTI_PARTY_ECDSA_CMP_KEY_GEN_NAKED_SIGN_KEY_H
#define SAFEHERON_MULTI_PARTY_ECDSA_CMP_KEY_GEN_NAKED_SIGN_KEY_H

#include <string>
#include "minimal_party.h"

namespace safeheron {
namespace multi_party_ecdsa{
namespace cmp{

class MinimalSignKey {
public:
    std::string workspace_id_;
    uint32_t threshold_;
    uint32_t n_parties_;
    MinimalLocalParty local_party_;
    std::vector<MinimalRemoteParty> remote_parties_;
    safeheron::curve::CurvePoint X_;

public:
    int get_remote_party_pos(const std::string &remote_party_id) const;

    bool ValidityTest() const;

    bool ToProtoObject(safeheron::proto::multi_party_ecdsa::cmp::MinimalSignKey &sign_key) const;

    bool FromProtoObject(const safeheron::proto::multi_party_ecdsa::cmp::MinimalSignKey &sign_key);

    bool ToBase64(std::string &b64) const;

    bool FromBase64(const std::string &b64);

    bool ToJsonString(std::string &json_str) const;

    bool FromJsonString(const std::string &json_str);
};

}
}
}

#endif //SAFEHERON_MULTI_PARTY_ECDSA_CMP_KEY_GEN_NAKED_SIGN_KEY_H
