
#ifndef SAFEHERON_MULTI_PARTY_ECDSA_GG18_SIGN_ONCE_CONTEXT_H
#define SAFEHERON_MULTI_PARTY_ECDSA_GG18_SIGN_ONCE_CONTEXT_H

#include <vector>
#include "crypto-curve/curve.h"
#include "crypto-bn/bn.h"
#include "mpc-flow/mpc-parallel-v2/mpc_context.h"
#include "../sign_key.h"
#include "t_party.h"
#include "round0.h"
#include "round1.h"
#include "round2.h"
#include "round3.h"
#include "round4.h"
#include "round5.h"
#include "round6.h"
#include "round7.h"
#include "round8.h"
#include "round9.h"

namespace safeheron {
namespace multi_party_ecdsa{
namespace gg18{
namespace sign{

class Context : public safeheron::mpc_flow::mpc_parallel_v2::MPCContext {
public:
    /**
     * Default constructor
     */
    Context(int total_parties);

    /**
     * A copy constructor
     */
    Context(const Context &ctx);

    /**
     * A copy assignment operator
     */
    Context &operator=(const Context &ctx);

public:
    void BindAllRounds();

    static bool CreateContext(Context &ctx, const std::string &sign_key_base64, const safeheron::bignum::BN &m);

public:
    safeheron::multi_party_ecdsa::gg18::SignKey sign_key_;
    safeheron::bignum::BN m_;
    safeheron::curve::CurvePoint V_;

    LocalTParty local_party_;
    std::vector<RemoteTParty> remote_parties_;
    Round0 round0_;
    Round1 round1_;
    Round2 round2_;
    Round3 round3_;
    Round4 round4_;
    Round5 round5_;
    Round6 round6_;
    Round7 round7_;
    Round8 round8_;
    Round9 round9_;


    safeheron::bignum::BN delta_;
    safeheron::curve::CurvePoint R_;
    safeheron::bignum::BN r_;
    safeheron::bignum::BN s_;
    uint32_t v_;

};

}
}
}
}

#endif //SAFEHERON_MULTI_PARTY_ECDSA_GG18_SIGN_ONCE_CONTEXT_H
