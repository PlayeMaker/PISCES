/************************ Include Files ************************/
#include "Drv_Crypto.h"
#include "Csm_Types.h"
#include "Crypto.h"
#include "Crypto_Cfg.h"

/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

static uint8  random_data[4];
static uint32 random_data_length = 4U;

static const Crypto_PrimitiveInfoType RandomSeed_PrimitiveInfo =
{
    .service = CRYPTO_RANDOMGENERATE,
    .algorithm =
    {
        .family = CRYPTO_ALGOFAM_RNG,
        .secondaryFamily = 0,
        .keyLength = 0,
        .mode = 0
    }
};

static const Crypto_JobPrimitiveInfoType RandomSeed_JobPrimitiveInfo =
{
    0U,
    &RandomSeed_PrimitiveInfo,
    0U,
    CRYPTO_PROCESSING_SYNC,
};

/* 4. 组装 Job */
static Crypto_JobType random_data_job =
{
    .jobId = 10,
    .jobState = CRYPTO_JOBSTATE_IDLE,
    .jobPrimitiveInputOutput =
    {
        .inputPtr = NULL_PTR,
        .inputLength = 0U,
        .secondaryInputPtr = NULL_PTR,
        .secondaryInputLength = 0U,
        .tertiaryInputPtr = NULL_PTR,
        .tertiaryInputLength = 0U,
        .outputPtr = random_data,
        .outputLengthPtr = &random_data_length,
        .secondaryOutputPtr = NULL_PTR,
        .secondaryOutputLengthPtr = NULL_PTR,
        .verifyPtr = NULL_PTR,
        .mode = CRYPTO_OPERATIONMODE_SINGLECALL,
        .cryIfKeyId = 0U,
    },
    .jobPrimitiveInfo = &RandomSeed_JobPrimitiveInfo,
    .jobRedirectionInfoRef = NULL_PTR,
    .cryptoKeyId = 0,
};

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
void Snf_Drv_Crypto_Init(void)
{
    Crypto_Init(NULL_PTR);
}

bool Snf_Drv_Crypto_Get_Random_Data(uint8* Data)
{
    Std_ReturnType ret;

    random_data_length = 4U;
    ret = Crypto_ProcessJob(CryptoConf_CryptoDriverObject_CryptoDriverObject_0, &random_data_job);

    if (ret != E_OK)
    {

        random_data[0] = 0x0CU;
        random_data[1] = 0x0CU;
        random_data[2] = 0x0CU;
        random_data[3] = 0x0CU;
    }
    for (int i = 0; i < 4; i++)
    {
        Data[i] = random_data[i];
    }
    return ret;
}