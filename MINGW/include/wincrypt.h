/*
 * wincrypt.h
 *
 * Cryptographic services API manifest constants and function prototypes.
 *
 * $Id: wincrypt.h,v 34e5e7606781 2016/05/23 18:31:09 keithmarshall $
 *
 * Written by Anders Norlander <anorland@hem2.passagen.se>
 * Copyright (C) 1998-2000, 2002-2004, 2006-2008, 2010, 2015,
 *   MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _WINCRYPT_H
#define _WINCRYPT_H
#pragma GCC system_header

#ifndef WINADVAPI
#define WINADVAPI
#endif

_BEGIN_C_DECLS

#define MS_DEF_PROV			__AW_EXTENDED__( MS_DEF_PROV )
#define MS_DEF_PROV_W			__AW_STRING_W__( MS_DEF_PROV_A )
#define MS_DEF_PROV_A			"Microsoft Base Cryptographic Provider v1.0"

#define MS_ENHANCED_PROV		__AW_EXTENDED__( MS_ENHANCED_PROV )
#define MS_ENHANCED_PROV_W		__AW_STRING_W__( MS_ENHANCED_PROV_A )
#define MS_ENHANCED_PROV_A		"Microsoft Enhanced Cryptographic Provider v1.0"

#define MS_STRONG_PROV			__AW_EXTENDED__( MS_STRONG_PROV )
#define MS_STRONG_PROV_W		__AW_STRING_W__( MS_STRONG_PROV_A )
#define MS_STRONG_PROV_A		"Microsoft Strong Cryptographic Provider"

#define MS_DEF_RSA_SIG_PROV		__AW_EXTENDED__( MS_DEF_RSA_SIG_PROV )
#define MS_DEF_RSA_SIG_PROV_W		__AW_STRING_W__( MS_DEF_RSA_SIG_PROV_A )
#define MS_DEF_RSA_SIG_PROV_A		"Microsoft RSA Signature Cryptographic Provider"

#define MS_DEF_RSA_SCHANNEL_PROV	__AW_EXTENDED__( MS_DEF_RSA_SCHANNEL_PROV )
#define MS_DEF_RSA_SCHANNEL_PROV_W	__AW_STRING_W__( MS_DEF_RSA_SCHANNEL_PROV_A )
#define MS_DEF_RSA_SCHANNEL_PROV_A	"Microsoft RSA SChannel Cryptographic Provider"

#define MS_DEF_DSS_PROV 		__AW_EXTENDED__( MS_DEF_DSS_PROV )
#define MS_DEF_DSS_PROV_W		__AW_STRING_W__( MS_DEF_DSS_PROV_A )
#define MS_DEF_DSS_PROV_A		"Microsoft Base DSS Cryptographic Provider"

#define MS_DEF_DSS_DH_PROV		__AW_EXTENDED__( MS_DEF_DSS_DH_PROV )
#define MS_DEF_DSS_DH_PROV_W		__AW_STRING_W__( MS_DEF_DSS_DH_PROV_A )
#define MS_DEF_DSS_DH_PROV_A		"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"

#define MS_ENH_DSS_DH_PROV		__AW_EXTENDED__( MS_ENH_DSS_DH_PROV )
#define MS_ENH_DSS_DH_PROV_W		__AW_STRING_W__( MS_ENH_DSS_DH_PROV_A )
#define MS_ENH_DSS_DH_PROV_A		"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"

#define MS_DEF_DH_SCHANNEL_PROV 	__AW_EXTENDED__( MS_DEF_DH_SCHANNEL_PROV )
#define MS_DEF_DH_SCHANNEL_PROV_W	__AW_STRING_W__( MS_DEF_DH_SCHANNEL_PROV_A )
#define MS_DEF_DH_SCHANNEL_PROV_A	"Microsoft DH SChannel Cryptographic Provider"

#define MS_SCARD_PROV			__AW_EXTENDED__( MS_SCARD_PROV )
#define MS_SCARD_PROV_W 		__AW_STRING_W__( MS_SCARD_PROV_A )
#define MS_SCARD_PROV_A 		"Microsoft Base Smart Card Crypto Provider"

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP
# define MS_ENH_RSA_AES_PROV		__AW_EXTENDED__( MS_ENH_RSA_AES_PROV )
# define MS_ENH_RSA_AES_PROV_W	 	__AW_STRING_W__( MS_ENH_RSA_AES_PROV_A )

# if _WIN32_WINNT == _WIN32_WINNT_WINXP
#  define MS_ENH_RSA_AES_PROV_A 	"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"

#else /* _WIN32_WINNT > _WIN32_WINNT_WINXP */
#  define MS_ENH_RSA_AES_PROV_A 	"Microsoft Enhanced RSA and AES Cryptographic Provider"
# endif
#endif

#define GET_ALG_CLASS(x)		     ((x) & ALG_CLASS_ALL)
#define GET_ALG_TYPE(x) 		     ((x) & 0x1E00)	/* x & 7680 */
#define GET_ALG_SID(x)			     ((x) & 0x01FF)	/* x &  511 */

#define ALG_CLASS_ANY					 0
#define ALG_CLASS_SIGNATURE 			    0x2000 	/*  8192 */
#define ALG_CLASS_MSG_ENCRYPT			    0x4000 	/* 16384 */
#define ALG_CLASS_DATA_ENCRYPT			    0x6000 	/* 24576 */
#define ALG_CLASS_HASH		 		    0x8000 	/* 32768 */
#define ALG_CLASS_KEY_EXCHANGE			    0xA000 	/* 40960 */
#define ALG_CLASS_ALL				    0xE000 	/* (0x0007 << 13) */

#define ALG_TYPE_ANY					 0
#define ALG_TYPE_DSS			   	    0x0200 	/*   512 */
#define ALG_TYPE_RSA				    0x0400 	/*  1024 */
#define ALG_TYPE_BLOCK				    0x0600 	/*  1536 */
#define ALG_TYPE_STREAM 			    0x0800 	/*  2048 */
#define ALG_TYPE_DH				    0x0A00 	/* (0x0005 << 9) */
#define ALG_TYPE_SECURECHANNEL			    0x0C00 	/* (6 << 9) */

#define ALG_SID_ANY					 0

#define ALG_SID_RSA_ANY 				 0
#define ALG_SID_RSA_PKCS				 1
#define ALG_SID_RSA_MSATWORK				 2
#define ALG_SID_RSA_ENTRUST				 3
#define ALG_SID_RSA_PGP 				 4

#define ALG_SID_DSS_ANY 				 0
#define ALG_SID_DSS_PKCS				 1
#define ALG_SID_DSS_DMS 				 2

#define ALG_SID_DES					 1
#define ALG_SID_3DES					 3
#define ALG_SID_DESX					 4
#define ALG_SID_IDEA					 5
#define ALG_SID_CAST					 6
#define ALG_SID_SAFERSK64				 7
#define ALG_SID_SAFERSK128				 8
#define ALG_SID_3DES_112				 9
#define ALG_SID_SKIPJACK				10
#define ALG_SID_TEK					11
#define ALG_SID_CYLINK_MEK				12
#define ALG_SID_RC5					13

#define ALG_SID_RC4					 1
#define ALG_SID_RC2					 2

#define ALG_SID_SEAL					 2

#define ALG_SID_MD2					 1
#define ALG_SID_MD4					 2
#define ALG_SID_MD5					 3
#define ALG_SID_SHA					 4
#define ALG_SID_MAC					 5
#define ALG_SID_RIPEMD					 6
#define ALG_SID_RIPEMD160				 7
#define ALG_SID_SSL3SHAMD5				 8
#define ALG_SID_HMAC					 9
#define ALG_SID_TLS1PRF 				10
#define ALG_SID_AES_128 				14
#define ALG_SID_AES_192 				15
#define ALG_SID_AES_256 				16
#define ALG_SID_AES					17
#define ALG_SID_EXAMPLE 				80

#define CALG_MD2			(ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4			(ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5			(ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA			(ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_SHA1				    CALG_SHA
#define CALG_MAC			(ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)
#define CALG_3DES			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | 3)
#define CALG_CYLINK_MEK 		(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | 12)
#define CALG_SKIPJACK			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | 10)
#define CALG_KEA_KEYX			(ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_STREAM | ALG_TYPE_DSS | 4)
#define CALG_RSA_SIGN			(ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN			(ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)
#define CALG_RSA_KEYX			(ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DES			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_DES)
#define CALG_RC2			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_RC2)
#define CALG_RC4			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_RC4)
#define CALG_SEAL			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_SEAL)
#define CALG_DH_EPHEM			(ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_STREAM | ALG_TYPE_DSS | ALG_SID_DSS_DMS)
#define CALG_DESX			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_DESX)
#define CALG_TLS1PRF			(ALG_CLASS_DHASH | ALG_TYPE_ANY | ALG_SID_TLS1PRF)
#define CALG_AES_128			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_128)
#define CALG_AES_192			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_192)
#define CALG_AES_256			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_256)
#define CALG_AES			(ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES)

/* dwFlags definitions for CryptAcquireContext
 */
#define CRYPT_VERIFYCONTEXT			0xF0000000
#define CRYPT_NEWKEYSET 			0x00000008
#define CRYPT_DELETEKEYSET			0x00000010	/* 16 */
#define CRYPT_MACHINE_KEYSET			0x00000020	/* 32 */
#define CRYPT_SILENT				0x00000040	/* 64 */

#define SIMPLEBLOB					 1
#define PUBLICKEYBLOB					 6
#define PRIVATEKEYBLOB					 7
#define PLAINTEXTKEYBLOB				 8
#define OPAQUEKEYBLOB					 9
#define PUBLICKEYBLOBEX 				10
#define SYMMETRICWRAPKEYBLOB				11

#define AT_KEYEXCHANGE					 1
#define AT_SIGNATURE					 2

#define CRYPT_USERDATA					 1

#define PKCS5_PADDING					 1

#define CRYPT_MODE_CBC					 1
#define CRYPT_MODE_ECB					 2
#define CRYPT_MODE_OFB					 3
#define CRYPT_MODE_CFB					 4
#define CRYPT_MODE_CTS					 5
#define CRYPT_MODE_CBCI 				 6
#define CRYPT_MODE_CFBP 				 7
#define CRYPT_MODE_OFBP 				 8
#define CRYPT_MODE_CBCOFM				 9
#define CRYPT_MODE_CBCOFMI				10

#define CRYPT_ENCRYPT				    0x0001
#define CRYPT_DECRYPT				    0x0002
#define CRYPT_EXPORT				    0x0004
#define CRYPT_READ				    0x0008
#define CRYPT_WRITE				    0x0010	/* 16 */
#define CRYPT_MAC				    0x0020	/* 32 */

#define HP_ALGID					 1
#define HP_HASHVAL					 2
#define HP_HASHSIZE					 4
#define HP_HMAC_INFO					 5

#define CRYPT_FAILED				     FALSE
#define CRYPT_SUCCEED				      TRUE
#define RCRYPT_SUCCEEDED(r)		      ((r) == CRYPT_SUCCEED)
#define RCRYPT_FAILED(r)		      ((r) == CRYPT_FAILED)

#define PP_ENUMALGS					 1
#define PP_ENUMCONTAINERS				 2
#define PP_IMPTYPE					 3
#define PP_NAME 					 4
#define PP_VERSION					 5
#define PP_CONTAINER					 6
#define PP_CHANGE_PASSWORD				 7
#define PP_KEYSET_SEC_DESCR				 8
#define PP_CERTCHAIN					 9
#define PP_KEY_TYPE_SUBTYPE				10
#define PP_PROVTYPE					16
#define PP_KEYSTORAGE					17
#define PP_APPLI_CERT					18
#define PP_SYM_KEYSIZE					19
#define PP_SESSION_KEYSIZE				20
#define PP_UI_PROMPT					21
#define PP_ENUMALGS_EX					22
#define PP_ENUMMANDROOTS				25
#define PP_ENUMELECTROOTS				26
#define PP_KEYSET_TYPE					27
#define PP_ADMIN_PIN					31
#define PP_KEYEXCHANGE_PIN				32
#define PP_SIGNATURE_PIN				33
#define PP_SIG_KEYSIZE_INC				34
#define PP_KEYX_KEYSIZE_INC				35
#define PP_UNIQUE_CONTAINER				36
#define PP_SGC_INFO					37
#define PP_USE_HARDWARE_RNG				38
#define PP_KEYSPEC					39
#define PP_ENUMEX_SIGNING_PROT				40

#define CRYPT_FIRST					 1
#define CRYPT_NEXT					 2

#define CRYPT_IMPL_HARDWARE				 1
#define CRYPT_IMPL_SOFTWARE				 2
#define CRYPT_IMPL_MIXED				 3
#define CRYPT_IMPL_UNKNOWN				 4

#define PROV_RSA_FULL					 1
#define PROV_RSA_SIG					 2
#define PROV_DSS					 3
#define PROV_FORTEZZA					 4
#define PROV_MS_EXCHANGE				 5
#define PROV_MS_MAIL					 5
#define PROV_SSL					 6
#define PROV_STT_MER					 7
#define PROV_STT_ACQ					 8
#define PROV_STT_BRND					 9
#define PROV_STT_ROOT					10
#define PROV_STT_ISS					11
#define PROV_RSA_SCHANNEL				12
#define PROV_DSS_DH					13
#define PROV_EC_ECDSA_SIG				14
#define PROV_EC_ECNRA_SIG				15
#define PROV_EC_ECDSA_FULL				16
#define PROV_EC_ECNRA_FULL				17
#define PROV_DH_SCHANNEL				18
#define PROV_SPYRUS_LYNKS				20
#define PROV_RNG					21
#define PROV_INTEL_SEC					22
#define PROV_RSA_AES					24

#define MAXUIDLEN					64

#define CUR_BLOB_VERSION				 2

#define X509_ASN_ENCODING				 1
#define PKCS_7_ASN_ENCODING			     65536

#define CERT_V1 					 0
#define CERT_V2 					 1
#define CERT_V3 					 2

#define CERT_E_CHAINING 		      (-2146762486)
#define CERT_E_CN_NO_MATCH		      (-2146762481)
#define CERT_E_EXPIRED			      (-2146762495)
#define CERT_E_PURPOSE			      (-2146762490)
#define CERT_E_REVOCATION_FAILURE	      (-2146762482)
#define CERT_E_REVOKED			      (-2146762484)
#define CERT_E_ROLE			      (-2146762493)
#define CERT_E_UNTRUSTEDROOT		      (-2146762487)
#define CERT_E_UNTRUSTEDTESTROOT	      (-2146762483)
#define CERT_E_VALIDITYPERIODNESTING	      (-2146762494)
#define CERT_E_WRONG_USAGE		      (-2146762480)
#define CERT_E_PATHLENCONST		      (-2146762492)
#define CERT_E_CRITICAL 		      (-2146762491)
#define CERT_E_ISSUERCHAINING		      (-2146762489)
#define CERT_E_MALFORMED		      (-2146762488)
#define CRYPT_E_REVOCATION_OFFLINE	      (-2146885613)
#define CRYPT_E_REVOKED 		      (-2146885616)
#define TRUST_E_BASIC_CONSTRAINTS	      (-2146869223)
#define TRUST_E_CERT_SIGNATURE		      (-2146869244)
#define TRUST_E_FAIL			      (-2146762485)

#define CERT_TRUST_NO_ERROR				 0
#define CERT_TRUST_IS_NOT_TIME_VALID		0x00000001
#define CERT_TRUST_IS_NOT_TIME_NESTED		0x00000002
#define CERT_TRUST_IS_REVOKED			0x00000004
#define CERT_TRUST_IS_NOT_SIGNATURE_VALID	0x00000008
#define CERT_TRUST_IS_NOT_VALID_FOR_USAGE	0x00000010	/*         16 */
#define CERT_TRUST_IS_UNTRUSTED_ROOT		0x00000020	/*         32 */
#define CERT_TRUST_REVOCATION_STATUS_UNKNOWN	0x00000040	/*         64 */
#define CERT_TRUST_IS_CYCLIC			0x00000080	/*        128 */
#define CERT_TRUST_IS_PARTIAL_CHAIN		0x00010000	/*      65336 */
#define CERT_TRUST_CTL_IS_NOT_TIME_VALID	0x00020000	/*     131072 */
#define CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID	0x00040000	/*     262144 */
#define CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE	0x00080000	/*     524288 */

#define CERT_TRUST_HAS_EXACT_MATCH_ISSUER	0x00000001
#define CERT_TRUST_HAS_KEY_MATCH_ISSUER 	0x00000002
#define CERT_TRUST_HAS_NAME_MATCH_ISSUER	0x00000004
#define CERT_TRUST_IS_SELF_SIGNED		0x00000008
#define CERT_TRUST_IS_COMPLEX_CHAIN		0x00010000	/*      65336 */

#define CERT_CHAIN_POLICY_BASE		       ((LPCSTR)(1))
#define CERT_CHAIN_POLICY_AUTHENTICODE	       ((LPCSTR)(2))
#define CERT_CHAIN_POLICY_AUTHENTICODE_TS      ((LPCSTR)(3))
#define CERT_CHAIN_POLICY_SSL		       ((LPCSTR)(4))
#define CERT_CHAIN_POLICY_BASIC_CONSTRAINTS    ((LPCSTR)(5))
#define CERT_CHAIN_POLICY_NT_AUTH	       ((LPCSTR)(6))

#define USAGE_MATCH_TYPE_AND				 0
#define USAGE_MATCH_TYPE_OR				 1

#define CERT_SIMPLE_NAME_STR				 1
#define CERT_OID_NAME_STR				 2
#define CERT_X500_NAME_STR				 3

#define CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG	0x00010000
#define CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG	0x00020000	/*     131072 */
#define CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG	0x00040000
#define CERT_NAME_STR_REVERSE_FLAG		0x02000000	/*   33554432 */
#define CERT_NAME_STR_COMMA_FLAG		0x04000000
#define CERT_NAME_STR_CRLF_FLAG 		0x08000000	/*  134217728 */
#define CERT_NAME_STR_NO_QUOTING_FLAG		0x10000000	/*  268435456 */
#define CERT_NAME_STR_NO_PLUS_FLAG		0x20000000	/*  536870912 */
#define CERT_NAME_STR_SEMICOLON_FLAG		0x40000000	/* 1073741824 */

#define CERT_FIND_ANY					 0
#define CERT_FIND_CERT_ID			0x00100000	/*    1048576 */
#define CERT_FIND_CTL_USAGE			0x000A0000	/*     653360 */
#define CERT_FIND_ENHKEY_USAGE			0x000A0000	/*     653360 */
#define CERT_FIND_EXISTING			0x000D0000	/*     851968 */
#define CERT_FIND_HASH				0x00010000	/*      65336 */
#define CERT_FIND_ISSUER_ATTR			0x00030004	/*     196612 */
#define CERT_FIND_ISSUER_NAME			0x00020004	/*     131076 */
#define CERT_FIND_ISSUER_OF			0x000C0000	/*     786432 */
#define CERT_FIND_KEY_IDENTIFIER		0x000F0000	/*     983040 */
#define CERT_FIND_KEY_SPEC			0x00090000	/*     589824 */
#define CERT_FIND_MD5_HASH			0x00040000	/*     262144 */
#define CERT_FIND_PROPERTY			0x00050000	/*     327680 */
#define CERT_FIND_PUBLIC_KEY			0x00060000	/*     393216 */
#define CERT_FIND_SHA1_HASH			0x00010000	/*      65536 */
#define CERT_FIND_SIGNATURE_HASH		0x000E0000	/*     917504 */
#define CERT_FIND_SUBJECT_ATTR			0x00030007	/*     196615 */
#define CERT_FIND_SUBJECT_CERT			0x000B0000	/*     720896 */
#define CERT_FIND_SUBJECT_NAME			0x00020007	/*     131079 */

#define CERT_FIND_SUBJECT_STR		   __AW_EXTENDED__( CERT_FIND_SUBJECT_STR )
#define CERT_FIND_SUBJECT_STR_A 		0x00070007	/*     458759 */
#define CERT_FIND_SUBJECT_STR_W 		0x00080007	/*     524295 */

#define CERT_FIND_ISSUER_STR		   __AW_EXTENDED__( CERT_FIND_ISSUER_STR )
#define CERT_FIND_ISSUER_STR_A			0x00070004	/*     458756 */
#define CERT_FIND_ISSUER_STR_W			0x00080004	/*     524292 */

#define CERT_FIND_OR_ENHKEY_USAGE_FLAG		0x00000010	/*         16 */
#define CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG	0x00000001
#define CERT_FIND_NO_ENHKEY_USAGE_FLAG		0x00000008
#define CERT_FIND_VALID_ENHKEY_USAGE_FLAG	0x00000020	/*         32 */
#define CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG	0x00000002

#define \
 CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG 	0x00000002
#define CERT_UNICODE_IS_RDN_ATTRS_FLAG		0x00000001

#define CERT_CHAIN_FIND_BY_ISSUER		0x00000001
#define \
 CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG	0x00000001
#define \
 CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG	0x00000002
#define \
 CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG	0x00008000	/*      32768 */
#define \
 CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG	0x00000004
#define \
 CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG	0x00000008
#define CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG	0x00004000	/*      16384 */

#define CERT_STORE_PROV_SYSTEM				10
#define CERT_SYSTEM_STORE_LOCAL_MACHINE 	0x00020000	/*     131072 */

#define szOID_PKIX_KP_SERVER_AUTH		"4235600"
#define szOID_SERVER_GATED_CRYPTO		"4235658"
#define szOID_SGC_NETSCAPE			"2.16.840.1.113730.4.1"
#define szOID_PKIX_KP_CLIENT_AUTH		"1.3.6.1.5.5.7.3.2"

/* dwFlag definitions for CryptGenKey
 */
#define CRYPT_EXPORTABLE			0x00000001
#define CRYPT_USER_PROTECTED			0x00000002
#define CRYPT_CREATE_SALT			0x00000004
#define CRYPT_UPDATE_KEY			0x00000008
#define CRYPT_NO_SALT				0x00000010
#define CRYPT_PREGEN				0x00000040
#define CRYPT_RECIPIENT 			0x00000010
#define CRYPT_INITIATOR 			0x00000040
#define CRYPT_ONLINE				0x00000080
#define CRYPT_SF				0x00000100
#define CRYPT_CREATE_IV 			0x00000200
#define CRYPT_KEK				0x00000400
#define CRYPT_DATA_KEY				0x00000800
#define CRYPT_VOLATILE				0x00001000
#define CRYPT_SGCKEY				0x00002000
#define CRYPT_ARCHIVABLE			0x00004000

#define KP_IV					0x00000001
#define KP_SALT 				0x00000002
#define KP_PADDING				0x00000003
#define KP_MODE 				0x00000004
#define KP_MODE_BITS				0x00000005
#define KP_PERMISSIONS				0x00000006
#define KP_ALGID				0x00000007
#define KP_BLOCKLEN				0x00000008
#define KP_KEYLEN				0x00000009
#define KP_SALT_EX				0x0000000A
#define KP_P					0x0000000B
#define KP_G					0x0000000C
#define KP_Q					0x0000000D
#define KP_X					0x0000000E
#define KP_Y					0x0000000F
#define KP_RA					0x00000010
#define KP_RB					0x00000011
#define KP_INFO 				0x00000012
#define KP_EFFECTIVE_KEYLEN			0x00000013
#define KP_SCHANNEL_ALG 			0x00000014
#define KP_PUB_PARAMS				0x00000027

#define CRYPT_FLAG_PCT1 			0x00000001
#define CRYPT_FLAG_SSL2 			0x00000002
#define CRYPT_FLAG_SSL3 			0x00000004
#define CRYPT_FLAG_TLS1 			0x00000008
#define CRYPT_FLAG_IPSEC			0x00000010
#define CRYPT_FLAG_SIGNING			0x00000020

#define SCHANNEL_MAC_KEY			0x00000000
#define SCHANNEL_ENC_KEY			0x00000001

#define INTERNATIONAL_USAGE			0x00000001

#if WINVER >= _WIN32_WINNT_WINXP
/* These are available only on Windows XP, Windows Server 2003, and later
 */
#define CMC_ADD_ATTRIBUTES		       ((LPCSTR)(63))
#define CMC_ADD_EXTENSIONS		       ((LPCSTR)(62))
#define X509_CERT_PAIR			       ((LPCSTR)(53))
#define X509_CERTIFICATE_TEMPLATE	       ((LPCSTR)(64))
#define X509_CROSS_CERT_DIST_POINTS	       ((LPCSTR)(58))
#define CMC_DATA			       ((LPCSTR)(59))
#define X509_NAME_CONSTRAINTS		       ((LPCSTR)(55))
#define X509_POLICY_CONSTRAINTS 	       ((LPCSTR)(57))
#define X509_POLICY_MAPPINGS		       ((LPCSTR)(56))
#define CMC_RESPONSE			       ((LPCSTR)(60))
#define CMC_STATUS			       ((LPCSTR)(61))
#endif /* WINVER >= _WIN32_WINNT_WINXP */

#define X509_ALGORITHM_IDENTIFIER	       ((LPCSTR)(74))
#define X509_ALTERNATE_NAME		       ((LPCSTR)(12))

/* FIXME: need #define X509_ANY_STRING */
#ifdef MINGW_TENTATIVE_ASSUMPTIONS
/* https://msdn.microsoft.com/en-us/library/aa378145.aspx suggests
 * that this may be an alias for...
 */
#define X509_ANY_STRING			       X509_NAME_VALUE
#endif

#define PKCS_ATTRIBUTE			       ((LPCSTR)(22))
#define X509_AUTHORITY_INFO_ACCESS	       ((LPCSTR)(32))
#define X509_AUTHORITY_KEY_ID		       ((LPCSTR) (9))
#define X509_AUTHORITY_KEY_ID2		       ((LPCSTR)(31))

#define szOID_BASIC_CONSTRAINTS 		 "2.5.29.10"
#define X509_BASIC_CONSTRAINTS		       ((LPCSTR) (13))
#define X509_BASIC_CONSTRAINTS2 	       ((LPCSTR) (15))
#define X509_BIOMETRIC_EXT		       ((LPCSTR) (71))
#define X509_BITS			       ((LPCSTR) (26))
#define X509_CERT			       ((LPCSTR)  (1))
#define X509_CERT_CRL_TO_BE_SIGNED	       ((LPCSTR)  (3))
#define X509_CERT_POLICIES		       ((LPCSTR) (16))
#define X509_CERT_REQUEST_TO_BE_SIGNED	       ((LPCSTR)  (4))
#define X509_CERT_TO_BE_SIGNED		       ((LPCSTR)  (2))
#define X509_CHOICE_OF_TIME		       ((LPCSTR) (30))
#define PKCS_CONTENT_INFO		       ((LPCSTR) (33))
#define PKCS_CONTENT_INFO_SEQUENCE_OF_ANY      ((LPCSTR) (23))
#define X509_CRL_DIST_POINTS		       ((LPCSTR) (35))

/* FIXME: need #define X509_CRL_REASON_CODE */
#ifdef MINGW_TENTATIVE_ASSUMPTIONS
/* https://msdn.microsoft.com/en-us/library/aa378145.aspx suggests
 * that this may be an alias for...
 */
#define X509_CRL_REASON_CODE		       X509_ENUMERATED
#endif

#define RSA_CSP_PUBLICKEYBLOB		       ((LPCSTR) (19))
#define PKCS_CTL			       ((LPCSTR) (37))
#define X509_DSS_PARAMETERS		       ((LPCSTR) (39))

/* FIXME: need #define X509_DSS_PUBLICKEY */
#ifdef MINGW_TENTATIVE_ASSUMPTIONS
/* https://msdn.microsoft.com/en-us/library/aa378145.aspx suggests
 * that this may be an alias for...
 */
#define X509_DSS_PUBLICKEY		       X509_MULTI_BYTE_UINT
#endif

#define X509_DSS_SIGNATURE		       ((LPCSTR) (40))
#define X509_ECC_SIGNATURE		       ((LPCSTR) (47))
#define X509_ENHANCED_KEY_USAGE 	       ((LPCSTR) (36))
#define X509_ENUMERATED 		       ((LPCSTR) (29))
#define X509_EXTENSIONS 		       ((LPCSTR)  (5))
#define X509_INTEGER			       ((LPCSTR) (27))
#define X509_ISSUING_DIST_POINT 	       ((LPCSTR) (54))
#define X509_KEY_ATTRIBUTES		       ((LPCSTR) (10))
#define X509_KEY_USAGE			       ((LPCSTR) (14))
#define X509_KEY_USAGE_RESTRICTION	       ((LPCSTR) (11))
#define X509_KEYGEN_REQUEST_TO_BE_SIGNED       ((LPCSTR) (21))
#define X509_LOGOTYPE_EXT		       ((LPCSTR) (70))
#define X509_MULTI_BYTE_INTEGER 	       ((LPCSTR) (28))
#define X509_MULTI_BYTE_UINT		       ((LPCSTR) (38))
#define X509_NAME			       ((LPCSTR)  (7))
#define X509_NAME_VALUE 		       ((LPCSTR)  (6))
#define X509_OBJECT_IDENTIFIER		       ((LPCSTR) (73))
#define X509_OCTET_STRING		       ((LPCSTR) (25))
#define X509_PUBLIC_KEY_INFO		       ((LPCSTR)  (8))
#define PKCS_RC2_CBC_PARAMETERS 	       ((LPCSTR) (41))
#define CNG_RSA_PUBLIC_KEY_BLOB 	       ((LPCSTR) (72))
#define PKCS_RSA_SSA_PSS_PARAMETERS	       ((LPCSTR) (75))
#define PKCS_RSAES_OAEP_PARAMETERS	       ((LPCSTR) (76))
#define ECC_CMS_SHARED_INFO		       ((LPCSTR) (77))
#define X509_SEQUENCE_OF_ANY		       ((LPCSTR) (34))
#define PKCS7_SIGNER_INFO		       ((LPCSTR)(500))
#define CMS_SIGNER_INFO 		       ((LPCSTR)(501))
#define PKCS_SMIME_CAPABILITIES 	       ((LPCSTR) (42))
#define PKCS_TIME_REQUEST		       ((LPCSTR) (18))

/* FIXME: need #define X509_UNICODE_ANY_STRING */
#ifdef MINGW_TENTATIVE_ASSUMPTIONS
/* https://msdn.microsoft.com/en-us/library/aa378145.aspx suggests
 * that this may be an alias for...
 */
#define X509_UNICODE_ANY_STRING 	       X509_UNICODE_NAME_VALUE
#endif

#define X509_UNICODE_NAME		       ((LPCSTR) (20))
#define X509_UNICODE_NAME_VALUE 	       ((LPCSTR) (24))
#define PKCS_UTC_TIME			       ((LPCSTR) (17))
#define OCSP_SIGNED_REQUEST		       ((LPCSTR) (65))
#define OCSP_REQUEST			       ((LPCSTR) (66))
#define OCSP_RESPONSE			       ((LPCSTR) (67))
#define OCSP_BASIC_SIGNED_RESPONSE	       ((LPCSTR) (68))
#define OCSP_BASIC_RESPONSE		       ((LPCSTR) (69))

enum
{ CRL_REASON_UNSPECIFIED=0,
  CRL_REASON_KEY_COMPROMISE=1,
  CRL_REASON_CA_COMPROMISE=2,
  CRL_REASON_AFFILIATION_CHANGED=3,
  CRL_REASON_SUPERSEDED=4,
  CRL_REASON_CESSATION_OF_OPERATION=5,
  CRL_REASON_CERTIFICATE_HOLD=6,
  CRL_REASON_REMOVE_FROM_CRL=7
};

/* FIXME: need #define CRYPT_DECODE_NOCOPY_FLAG */

#define CRYPT_ENCODE_ALLOC_FLAG 				0x00008000
#define CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG	0x40000000
#define CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG	0x80000000
#define CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG	0x20000000
#define CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG	0x10000000

/* Object ID codes from https://support.microsoft.com/en-gb/kb/287547
 * and/or from https://msdn.microsoft.com/en-us/library/aa378145.aspx
 */
#define szOID_RSA				"1.2.840.113549"
#define szOID_PKCS				"1.2.840.113549.1"
#define szOID_RSA_HASH				"1.2.840.113549.2"
#define szOID_RSA_ENCRYPT			"1.2.840.113549.3"
#define szOID_PKCS_1				"1.2.840.113549.1.1"
#define szOID_PKCS_2				"1.2.840.113549.1.2"
#define szOID_PKCS_3				"1.2.840.113549.1.3"
#define szOID_PKCS_4				"1.2.840.113549.1.4"
#define szOID_PKCS_5				"1.2.840.113549.1.5"
#define szOID_PKCS_6				"1.2.840.113549.1.6"
#define szOID_PKCS_7				"1.2.840.113549.1.7"
#define szOID_PKCS_8				"1.2.840.113549.1.8"
#define szOID_PKCS_9				"1.2.840.113549.1.9"
#define szOID_PKCS_10				"1.2.840.113549.1.10"
#define szOID_PKCS_12				"1.2.840.113549.1.12"
#define szOID_RSA_MD2				"1.2.840.113549.1.1.2"
#define szOID_RSA_MD4				"1.2.840.113549.1.1.3"
#define szOID_RSA_MD5				"1.2.840.113549.2.5"
#define szOID_RSA_RSA				"1.2.840.113549.1.1.1"
#define szOID_RSA_MD2RSA			"1.2.840.113549.1.1.2"
#define szOID_RSA_MD4RSA			"1.2.840.113549.1.1.3"
#define szOID_RSA_MD5RSA			"1.2.840.113549.1.1.4"
#define szOID_RSA_SHA1RSA			"1.2.840.113549.1.1.5"
#define szOID_RSA_SETOAEP_RSA			"1.2.840.113549.1.1.5"
#define szOID_RSA_DH				"1.2.840.113549.1.3.1"
#define szOID_RSA_data				"1.2.840.113549.1.7.1"
#define szOID_RSA_signedData			"1.2.840.113549.1.7.2"
#define szOID_RSA_envelopedData 		"1.2.840.113549.1.7.3"
#define szOID_RSA_signEnvData			"1.2.840.113549.1.7.4"
#define szOID_RSA_digestedData			"1.2.840.113549.1.7.5"
#define szOID_RSA_hashedData			"1.2.840.113549.1.7.5"
#define szOID_RSA_encryptedData 		"1.2.840.113549.1.7.6"
#define szOID_RSA_emailAddr			"1.2.840.113549.1.9.1"
#define szOID_RSA_unstructName			"1.2.840.113549.1.9.2"
#define szOID_RSA_contentType			"1.2.840.113549.1.9.3"
#define szOID_RSA_messageDigest 		"1.2.840.113549.1.9.4"
#define szOID_RSA_signingTime			"1.2.840.113549.1.9.5"
#define szOID_RSA_iSign			"1.2.840.113549.1.9.6"
#define szOID_RSA_challengePwd			"1.2.840.113549.1.9.7"
#define szOID_RSA_unstructAddr			"1.2.840.113549.1.9.8"
#define szOID_RSA_extCertAttrs			"1.2.840.113549.1.9.9"
#define szOID_RSA_SMIMECapabilities		"1.2.840.113549.1.9.15"
#define szOID_RSA_preferSignedData		"1.2.840.113549.1.9.15.1"
#define szOID_RSA_RC2CBC			"1.2.840.113549.3.2"
#define szOID_RSA_RC4				"1.2.840.113549.3.4"
#define szOID_RSA_DES_EDE3_CBC			"1.2.840.113549.3.7"
#define szOID_RSA_RC5_CBCPad			"1.2.840.113549.3.9"
#define szOID_ANSI_x942 			"1.2.840.10046"
#define szOID_ANSI_x942_DH			"1.2.840.10046.2.1"
#define szOID_X957				"1.2.840.10040"
#define szOID_X957_DSA				"1.2.840.10040.4.1"
#define szOID_DATA STRUCTURE			"1.2.840.10040.4.3"
#define szOID_DS				"2.5"
#define szOID_DSALG				"2.5.8"
#define szOID_DSALG_CRPT			"2.5.8.1"
#define szOID_DSALG_HASH			"2.5.8.2"
#define szOID_DSALG_SIGN			"2.5.8.3"
#define szOID_DSALG_RSA 			"2.5.8.1.1"
#define szOID_OIW				"1.3.14"
#define szOID_OIWSEC				"1.3.14.3.2"
#define szOID_OIWSEC_md4RSA			"1.3.14.3.2.2"
#define szOID_OIWSEC_md5RSA			"1.3.14.3.2.3"
#define szOID_OIWSEC_md4RSA2			"1.3.14.3.2.4"
#define szOID_OIWSEC_desECB			"1.3.14.3.2.6"
#define szOID_OIWSEC_desCBC			"1.3.14.3.2.7"
#define szOID_OIWSEC_desOFB			"1.3.14.3.2.8"
#define szOID_OIWSEC_desCFB			"1.3.14.3.2.9"
#define szOID_OIWSEC_desMAC			"1.3.14.3.2.10"
#define szOID_OIWSEC_rsaSign			"1.3.14.3.2.11"
#define szOID_OIWSEC_dsa			"1.3.14.3.2.12"
#define szOID_OIWSEC_shaDSA			"1.3.14.3.2.13"
#define szOID_OIWSEC_mdc2RSA			"1.3.14.3.2.14"
#define szOID_OIWSEC_shaRSA			"1.3.14.3.2.15"
#define szOID_OIWSEC_dhCommMod			"1.3.14.3.2.16"
#define szOID_OIWSEC_desEDE			"1.3.14.3.2.17"
#define szOID_OIWSEC_sha			"1.3.14.3.2.18"
#define szOID_OIWSEC_mdc2			"1.3.14.3.2.19"
#define szOID_OIWSEC_dsaComm			"1.3.14.3.2.20"
#define szOID_OIWSEC_dsaCommSHA 		"1.3.14.3.2.21"
#define szOID_OIWSEC_rsaXchg			"1.3.14.3.2.22"
#define szOID_OIWSEC_keyHashSeal		"1.3.14.3.2.23"
#define szOID_OIWSEC_md2RSASign 		"1.3.14.3.2.24"
#define szOID_OIWSEC_md5RSASign 		"1.3.14.3.2.25"
#define szOID_OIWSEC_sha1			"1.3.14.3.2.26"
#define szOID_OIWSEC_dsaSHA1			"1.3.14.3.2.27"
#define szOID_OIWSEC_dsaCommSHA1		"1.3.14.3.2.28"
#define szOID_OIWSEC_sha1RSASign		"1.3.14.3.2.29"
#define szOID_OIWDIR				"1.3.14.7.2"
#define szOID_OIWDIR_CRPT			"1.3.14.7.2.1"
#define szOID_OIWDIR_HASH			"1.3.14.7.2.2"
#define szOID_OIWDIR_SIGN			"1.3.14.7.2.3"
#define szOID_OIWDIR_md2			"1.3.14.7.2.2.1"
#define szOID_OIWDIR_md2RSA			"1.3.14.7.2.3.1"
#define szOID_INFOSEC				"2.16.840.1.101.2.1"
#define szOID_INFOSEC_sdnsSignature		"2.16.840.1.101.2.1.1.1"
#define szOID_INFOSEC_mosaicSignature		"2.16.840.1.101.2.1.1.2"
#define szOID_INFOSEC_sdnsConfidentiality	"2.16.840.1.101.2.1.1.3"
#define szOID_INFOSEC_mosaicConfidentiality	"2.16.840.1.101.2.1.1.4"
#define szOID_INFOSEC_sdnsIntegrity		"2.16.840.1.101.2.1.1.5"
#define szOID_INFOSEC_mosaicIntegrity		"2.16.840.1.101.2.1.1.6"
#define szOID_INFOSEC_sdnsTokenProtection	"2.16.840.1.101.2.1.1.7"
#define szOID_INFOSEC_mosaicTokenProtection	"2.16.840.1.101.2.1.1.8"
#define szOID_INFOSEC_sdnsKeyManagement 	"2.16.840.1.101.2.1.1.9"
#define szOID_INFOSEC_mosaicKeyManagement	"2.16.840.1.101.2.1.1.10"
#define szOID_INFOSEC_sdnsKMandSig		"2.16.840.1.101.2.1.1.11"
#define szOID_INFOSEC_mosaicKMandSig		"2.16.840.1.101.2.1.1.12"
#define szOID_INFOSEC_SuiteASignature		"2.16.840.1.101.2.1.1.13"
#define szOID_INFOSEC_SuiteAConfidentiality 	"2.16.840.1.101.2.1.1.14"
#define szOID_INFOSEC_SuiteAIntegrity		"2.16.840.1.101.2.1.1.15"
#define szOID_INFOSEC_SuiteATokenProtection	"2.16.840.1.101.2.1.1.16"
#define szOID_INFOSEC_SuiteAKeyManagement	"2.16.840.1.101.2.1.1.17"
#define szOID_INFOSEC_SuiteAKMandSig		"2.16.840.1.101.2.1.1.18"
#define szOID_INFOSEC_mosaicUpdatedSig		"2.16.840.1.101.2.1.1.19"
#define szOID_INFOSEC_mosaicKMandUpdSig 	"2.16.840.1.101.2.1.1.20"
#define szOID_INFOSEC_mosaicUpdatedInteg	"2.16.840.1.101.2.1.1.21"
#define szOID_PKIX_NO_SIGNATURE 		"1.3.6.1.5.5.7.6.2"

#define szOID_COMMON_NAME			"2.5.4.3"
#define szOID_COUNTRY_NAME			"2.5.4.6"
#define szOID_DEVICE_SERIAL_NUMBER		"2.5.4.5"
#define szOID_DOMAIN_COMPONENT			"0.9.2342.19200300.100.1.25"
#define szOID_GIVEN_NAME			"2.5.4.42"
#define szOID_INITIALS				"2.5.4.43"
#define szOID_LOCALITY_NAME			"2.5.4.7"
#define szOID_ORGANIZATION_NAME 		"2.5.4.10"
#define szOID_ORGANIZATIONAL_UNIT_NAME		"2.5.4.11"
#define szOID_STATE_OR_PROVINCE_NAME		"2.5.4.8"
#define szOID_STREET_ADDRESS			"2.5.4.9"
#define szOID_SUR_NAME				"2.5.4.4"
#define szOID_TITLE				"2.5.4.12"
#define szOID_BASIC_CONSTRAINTS2	 	"2.5.29.19"
#define szOID_APPLICATION_CERT_POLICIES 	"1.3.6.1.4.1.311.21.10"
#define szOID_APPLICATION_POLICY_CONSTRAINTS	"1.3.6.1.4.1.311.21.12"
#define szOID_APPLICATION_POLICY_MAPPINGS	"1.3.6.1.4.1.311.21.11"
#define szOID_AUTHORITY_INFO_ACCESS		"1.3.6.1.5.5.7.1.1"
#define szOID_AUTHORITY_KEY_IDENTIFIER		"2.5.29.1"
#define szOID_AUTHORITY_KEY_IDENTIFIER2 	"2.5.29.35"

#define szOID_BIOMETRIC_EXT			"1.3.6.1.5.5.7.1.2"
#define szOID_CERT_EXTENSIONS			"1.3.6.1.4.1.311.2.1.14"
#define szOID_CERT_POLICIES			"2.5.29.32"

#if WINVER >= _WIN32_WINNT_WINXP
/* These are available only on Windows XP, Windows Server 2003, and later
 */
#define szOID_CERTIFICATE_TEMPLATE		"1.3.6.1.4.1.311.21.7"
#define szOID_CRL_NUMBER			"2.5.29.20"
#define szOID_CROSS_CERT_DIST_POINTS		"1.3.6.1.4.1.311.10.9.1"
#define szOID_DELTA_CRL_INDICATOR		"2.5.29.27"
#define szOID_ENROLLMENT_NAME_VALUE_PAIR	"1.3.6.1.4.1.311.13.2.1"
#define szOID_FRESHEST_CRL			"2.5.29.46"
#define szOID_ISSUING_DIST_POINT		"2.5.29.28"
#define szOID_NAME_CONSTRAINTS			"2.5.29.30"
#endif /* WINVER >= _WIN32_WINNT_WINXP */

#define szOID_CRL_DIST_POINTS			"2.5.29.31"
#define szOID_CRL_REASON_CODE			"2.5.29.21"
#define szOID_CRL_VIRTUAL_BASE			"1.3.6.1.4.1.311.21.3"
#define szOID_ECC_PUBLIC_KEY			"1.2.840.10045.2.1"
#define szOID_ECDSA_SPECIFIED			"1.2.840.10045.4.3"
#define szOID_ENHANCED_KEY_USAGE		"2.5.29.37"
#define szOID_ISSUER_ALT_NAME			"2.5.29.8"
#define szOID_ISSUER_ALT_NAME2			"2.5.29.18"
#define szOID_KEY_ATTRIBUTES			"2.5.29.2"
#define szOID_KEY_USAGE 			"2.5.29.4"
#define szOID_KEY_USAGE_RESTRICTION		"2.5.29.4"
#define szOID_LOGOTYPE_EXT			"1.3.6.1.5.5.7.1.12"
#define szOID_NEXT_UPDATE_LOCATION		"1.3.6.1.4.1.311.10.2"
#define szOID_POLICY_CONSTRAINTS		"2.5.29.36"
#define szOID_POLICY_MAPPINGS			"2.5.29.33"
#define szOID_RSA_SSA_PSS			"1.2.840.113549.1.1.10"
#define szOID_RSAES_OAEP			"1.2.840.113549.1.1.7"
#define szOID_SUBJECT_ALT_NAME			"2.5.29.7"
#define szOID_SUBJECT_ALT_NAME2 		"2.5.29.17"
#define szOID_SUBJECT_KEY_IDENTIFIER		"2.5.29.14"

typedef struct _CERT_BASIC_CONSTRAINTS2_INFO
{ BOOL				 fCA;
  BOOL				 fPathLenConstraint;
  DWORD 			 dwPathLenConstraint;
} CERT_BASIC_CONSTRAINTS2_INFO, *PCERT_BASIC_CONSTRAINTS2_INFO;

typedef VOID (WINAPI *PFN_CRYPT_FREE)( LPVOID );
typedef LPVOID (WINAPI *PFN_CRYPT_ALLOC)( size_t );

typedef struct _CRYPT_ENCODE_PARA
{ DWORD 			 cbSize;
  PFN_CRYPT_ALLOC		 pfnAlloc;
  PFN_CRYPT_FREE		 pfnFree;
} CRYPT_ENCODE_PARA, *PCRYPT_ENCODE_PARA;

/* FIXME: definition missing. */
typedef struct _CRYPT_DECODE_PARA *PCRYPT_DECODE_PARA;

typedef UINT ALG_ID;
typedef struct _VTableProvStruc
{ FARPROC			 FuncVerifyImage;
} VTableProvStruc, *PVTableProvStruc;

typedef ULONG HCRYPTPROV;
typedef ULONG HCRYPTKEY;
typedef ULONG HCRYPTHASH;
typedef PVOID HCERTSTORE;
typedef PVOID HCRYPTMSG;
typedef PVOID HCERTCHAINENGINE;

typedef struct _CRYPTOAPI_BLOB
{ DWORD 			 cbData;
  BYTE				*pbData;
};
typedef struct _CRYPTOAPI_BLOB CRYPT_INTEGER_BLOB, *PCRYPT_INTEGER_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_UINT_BLOB, *PCRYPT_UINT_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_OBJID_BLOB, *PCRYPT_OBJID_BLOB;
typedef struct _CRYPTOAPI_BLOB CERT_NAME_BLOB, *PCERT_NAME_BLOB;
typedef struct _CRYPTOAPI_BLOB CERT_RDN_VALUE_BLOB, *PCERT_RDN_VALUE_BLOB;
typedef struct _CRYPTOAPI_BLOB CERT_BLOB, *PCERT_BLOB;
typedef struct _CRYPTOAPI_BLOB CRL_BLOB, *PCRL_BLOB;
typedef struct _CRYPTOAPI_BLOB DATA_BLOB, *PDATA_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_DATA_BLOB, *PCRYPT_DATA_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_HASH_BLOB, *PCRYPT_HASH_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_DIGEST_BLOB, *PCRYPT_DIGEST_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_DER_BLOB, *PCRYPT_DER_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_ATTR_BLOB, *PCRYPT_ATTR_BLOB;

typedef struct _SSL_EXTRA_CERT_CHAIN_POLICY_PARA
{ /* not described in SDK; has the same layout as HTTPSPolicyCallbackData
   */
  DWORD 			 cbStruct;
  DWORD 			 dwAuthType;
  DWORD 			 fdwChecks;
  LPWSTR			 pwszServerName;
};
typedef struct _SSL_EXTRA_CERT_CHAIN_POLICY_PARA SSL_EXTRA_CERT_CHAIN_POLICY_PARA;
typedef struct _SSL_EXTRA_CERT_CHAIN_POLICY_PARA *PSSL_EXTRA_CERT_CHAIN_POLICY_PARA;
typedef struct _SSL_EXTRA_CERT_CHAIN_POLICY_PARA HTTPSPolicyCallbackData;
typedef struct _SSL_EXTRA_CERT_CHAIN_POLICY_PARA *PHTTPSPolicyCallbackData;

/* #if _WIN32_WINNT >= _WIN32_WINNT_WIN2K */
typedef struct _CERT_CHAIN_POLICY_PARA
{ DWORD 			 cbSize;
  DWORD 			 dwFlags;
  void				*pvExtraPolicyPara;
} CERT_CHAIN_POLICY_PARA, *PCERT_CHAIN_POLICY_PARA;

typedef struct _CERT_CHAIN_POLICY_STATUS
{ DWORD 			 cbSize;
  DWORD 			 dwError;
  LONG			 	 lChainIndex;
  LONG				 lElementIndex;
  void				*pvExtraPolicyStatus;
} CERT_CHAIN_POLICY_STATUS, *PCERT_CHAIN_POLICY_STATUS;
/* #endif _WIN32_WINNT >= _WIN32_WINNT_WIN2K */

typedef struct _CRYPT_ALGORITHM_IDENTIFIER
{ LPSTR 			 pszObjId;
  CRYPT_OBJID_BLOB 		 Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, *PCRYPT_ALGORITHM_IDENTIFIER;

typedef struct _CRYPT_BIT_BLOB
{ DWORD 			 cbData;
  BYTE				*pbData;
  DWORD 			 cUnusedBits;
} CRYPT_BIT_BLOB, *PCRYPT_BIT_BLOB;

typedef struct _CERT_PUBLIC_KEY_INFO
{ CRYPT_ALGORITHM_IDENTIFIER	 Algorithm;
  CRYPT_BIT_BLOB		 PublicKey;
} CERT_PUBLIC_KEY_INFO, *PCERT_PUBLIC_KEY_INFO;

typedef struct _CERT_EXTENSION
{ LPSTR 			 pszObjId;
  BOOL				 fCritical;
  CRYPT_OBJID_BLOB		 Value;
} CERT_EXTENSION, *PCERT_EXTENSION;

typedef struct _CERT_INFO
{ DWORD 			 dwVersion;
  CRYPT_INTEGER_BLOB		 SerialNumber;
  CRYPT_ALGORITHM_IDENTIFIER	 SignatureAlgorithm;
  CERT_NAME_BLOB		 Issuer;
  FILETIME			 NotBefore;
  FILETIME			 NotAfter;
  CERT_NAME_BLOB		 Subject;
  CERT_PUBLIC_KEY_INFO		 SubjectPublicKeyInfo;
  CRYPT_BIT_BLOB		 IssuerUniqueId;
  CRYPT_BIT_BLOB		 SubjectUniqueId;
  DWORD 			 cExtension;
  PCERT_EXTENSION		 rgExtension;
} CERT_INFO, *PCERT_INFO;

typedef struct _CERT_CONTEXT
{ DWORD 			 dwCertEncodingType;
  BYTE				*pbCertEncoded;
  DWORD 			 cbCertEncoded;
  PCERT_INFO			 pCertInfo;
  HCERTSTORE			 hCertStore;
} CERT_CONTEXT, *PCERT_CONTEXT;

typedef const CERT_CONTEXT *PCCERT_CONTEXT;

typedef struct _CTL_USAGE
{ DWORD 			 cUsageIdentifier;
  LPSTR 			*rgpszUsageIdentifier;
} CTL_USAGE, *PCTRL_USAGE, CERT_ENHKEY_USAGE, *PCERT_ENHKEY_USAGE;

typedef struct _CERT_USAGE_MATCH
{ DWORD 			 dwType;
  CERT_ENHKEY_USAGE		 Usage;
} CERT_USAGE_MATCH, *PCERT_USAGE_MATCH;

/* #if _WIN32_WINNT >= _WIN32_WINNT_WIN2K */
typedef struct _CERT_CHAIN_PARA
{ DWORD 			 cbSize;
  CERT_USAGE_MATCH		 RequestedUsage;

# if CERT_CHAIN_PARA_HAS_EXTRA_FIELDS

  CERT_USAGE_MATCH		 RequestedIssuancePolicy;
  DWORD 			 dwUrlRetrievalTimeout;
  BOOL				 fCheckRevocationFreshnessTime;
  DWORD 			 dwRevocationFreshnessTime;
# endif

} CERT_CHAIN_PARA, *PCERT_CHAIN_PARA;

typedef BOOL (WINAPI *PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK)( PCCERT_CONTEXT, void * );

typedef struct _CERT_CHAIN_FIND_BY_ISSUER_PARA
{ DWORD 					 cbSize;
  LPCSTR					 pszUsageIdentifier;
  DWORD 					 dwKeySpec;
  DWORD 					 dwAcquirePrivateKeyFlags;
  DWORD 					 cIssuer;
  CERT_NAME_BLOB				*rgIssuer;
  PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK	 pfnFIndCallback;
  void						*pvFindArg;
  DWORD 					*pdwIssuerChainIndex;
  DWORD 					*pdwIssuerElementIndex;
} CERT_CHAIN_FIND_BY_ISSUER_PARA, *PCERT_CHAIN_FIND_BY_ISSUER_PARA;
/* #endif _WIN32_WINNT >= _WIN32_WINNT_WIN2K */

typedef struct _CERT_TRUST_STATUS
{ DWORD 			 dwErrorStatus;
  DWORD 			 dwInfoStatus;
} CERT_TRUST_STATUS, *PCERT_TRUST_STATUS;

typedef struct _CRL_ENTRY
{ CRYPT_INTEGER_BLOB		 SerialNumber;
  FILETIME			 RevocationDate;
  DWORD 			 cExtension;
  PCERT_EXTENSION		 rgExtension;
} CRL_ENTRY, *PCRL_ENTRY;

typedef struct _CRL_INFO
{ DWORD 			 dwVersion;
  CRYPT_ALGORITHM_IDENTIFIER	 SignatureAlgorithm;
  CERT_NAME_BLOB		 Issuer;
  FILETIME			 ThisUpdate;
  FILETIME			 NextUpdate;
  DWORD 			 cCRLEntry;
  PCRL_ENTRY			 rgCRLEntry;
  DWORD 			 cExtension;
  PCERT_EXTENSION		 rgExtension;
} CRL_INFO, *PCRL_INFO;

typedef struct _CRL_CONTEXT
{ DWORD 			 dwCertEncodingType;
  BYTE				*pbCrlEncoded;
  DWORD 			 cbCrlEncoded;
  PCRL_INFO			 pCrlInfo;
  HCERTSTORE			 hCertStore;
} CRL_CONTEXT, *PCRL_CONTEXT;

typedef const CRL_CONTEXT *PCCRL_CONTEXT;
typedef struct _CERT_REVOCATION_CRL_INFO
{ DWORD 			 cbSize;
  PCCRL_CONTEXT 		 pBaseCRLContext;
  PCCRL_CONTEXT 		 pDeltaCRLContext;
  PCRL_ENTRY			 pCrlEntry;
  BOOL fDeltaCrlEntry;
} CERT_REVOCATION_CRL_INFO, *PCERT_REVOCATION_CRL_INFO;

typedef struct _CERT_REVOCATION_INFO
{ DWORD 			 cbSize;
  DWORD 			 dwRevocationResult;
  LPCSTR			 pszRevocationOid;
  LPVOID			 pvOidSpecificInfo;
  BOOL				 fHasFreshnessTime;
  DWORD 			 dwFreshnessTime;
  PCERT_REVOCATION_CRL_INFO	 pCrlInfo;
} CERT_REVOCATION_INFO, *PCERT_REVOCATION_INFO;

/* #if _WIN32_WINNT >= _WIN32_WINNT_WIN2K */
typedef struct _CERT_CHAIN_ELEMENT
{ DWORD 			 cbSize;
  PCCERT_CONTEXT		 pCertContext;
  CERT_TRUST_STATUS		 TrustStatus;
  PCERT_REVOCATION_INFO 	 pRevocationInfo;
  PCERT_ENHKEY_USAGE		 pIssuanceUsage;
  PCERT_ENHKEY_USAGE		 pApplicationUsage;
} CERT_CHAIN_ELEMENT, *PCERT_CHAIN_ELEMENT;
/* #endif _WIN32_WINNT >= _WIN32_WINNT_WIN2K */

typedef struct _CRYPT_ATTRIBUTE
{ LPSTR 			 pszObjId;
  DWORD 			 cValue;
  PCRYPT_ATTR_BLOB		 rgValue;
} CRYPT_ATTRIBUTE, *PCRYPT_ATTRIBUTE;

typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE
{ LPSTR 			 pszObjId;
  CRYPT_OBJID_BLOB		 rgValue;
} CRYPT_ATTRIBUTE_TYPE_VALUE, *PCRYPT_ATTRIBUTE_TYPE_VALUE;

typedef struct _CTL_ENTRY
{ CRYPT_DATA_BLOB		 SubjectIdentifier;
  DWORD 			 cAttribute;
  PCRYPT_ATTRIBUTE		 rgAttribute;
} CTL_ENTRY, *PCTL_ENTRY;

typedef struct _CTL_INFO
{ DWORD 			 dwVersion;
  CTL_USAGE			 SubjectUsage;
  CRYPT_DATA_BLOB		 ListIdentifier;
  CRYPT_INTEGER_BLOB		 SequenceNumber;
  FILETIME			 ThisUpdate;
  FILETIME			 NextUpdate;
  CRYPT_ALGORITHM_IDENTIFIER	 SubjectAlgorithm;
  DWORD 			 cCTLEntry;
  PCTL_ENTRY			 rgCTLEntry;
  DWORD 			 cExtension;
  PCERT_EXTENSION		 rgExtension;
} CTL_INFO, *PCTL_INFO;

typedef struct _CTL_CONTEXT
{ DWORD 			 dwMsgAndCertEncodingType;
  BYTE				*pbCtlEncoded;
  DWORD 			 cbCtlEncoded;
  PCTL_INFO			 pCtlInfo;
  HCERTSTORE			 hCertStore;
  HCRYPTMSG			 hCryptMsg;
  BYTE				*pbCtlContent;
  DWORD 			 cbCtlContent;
} CTL_CONTEXT, *PCTL_CONTEXT;

typedef const CTL_CONTEXT *PCCTL_CONTEXT;
typedef struct _CERT_TRUST_LIST_INFO
{ DWORD 			 cbSize;
  PCTL_ENTRY			 pCtlEntry;
  PCCTL_CONTEXT 		 pCtlContext;
} CERT_TRUST_LIST_INFO, *PCERT_TRUST_LIST_INFO;

typedef struct _CERT_SIMPLE_CHAIN
{ DWORD 			 cbSize;
  CERT_TRUST_STATUS		 TrustStatus;
  DWORD 			 cElement;
  PCERT_CHAIN_ELEMENT		*rgpElement;
  PCERT_TRUST_LIST_INFO 	 pTrustListInfo;
  BOOL				 fHasRevocationFreshnessTime;
  DWORD 			 dwRevocationFreshnessTime;
} CERT_SIMPLE_CHAIN, *PCERT_SIMPLE_CHAIN;

/* #if _WIN32_WINNT >= _WIN32_WINNT_WIN2K */
typedef const struct _CERT_CHAIN_CONTEXT* PCCERT_CHAIN_CONTEXT;
typedef struct _CERT_CHAIN_CONTEXT
{ DWORD 			 cbSize;
  CERT_TRUST_STATUS		 TrustStatus;
  DWORD 			 cChain;
  PCERT_SIMPLE_CHAIN		*rgpChain;
  DWORD 			 cLowerQualityChainContext;
  PCCERT_CHAIN_CONTEXT		*rgpLowerQualityChainContext;
  BOOL				 fHasRevocationFreshnessTime;
  DWORD 			 dwRevocationFreshnessTime;
} CERT_CHAIN_CONTEXT, *PCERT_CHAIN_CONTEXT;
/* #endif _WIN32_WINNT >= _WIN32_WINNT_WIN2K */

typedef struct _PROV_ENUMALGS
{ ALG_ID			 aiAlgid;
  DWORD 			 dwBitLen;
  DWORD 			 dwNameLen;
  CHAR				 szName[20];
} PROV_ENUMALGS;

typedef struct _PUBLICKEYSTRUC
{ BYTE				 bType;
  BYTE				 bVersion;
  WORD				 reserved;
  ALG_ID			 aiKeyAlg;
} BLOBHEADER, PUBLICKEYSTRUC;

typedef struct _RSAPUBKEY
{ DWORD 			 magic;
  DWORD 			 bitlen;
  DWORD 			 pubexp;
} RSAPUBKEY;

typedef struct _HMAC_Info
{ ALG_ID			 HashAlgid;
  BYTE				*pbInnerString;
  DWORD 			 cbInnerString;
  BYTE				*pbOuterString;
  DWORD 			 cbOuterString;
} HMAC_INFO, *PHMAC_INFO;

#if WINVER >= _WIN32_WINNT_WINXP
/* Available only on Windows-XP, Windows Server 2003, and later.
 */
typedef struct _CMC_ADD_ATTRIBUTES_INFO
{ DWORD 			 dwCmcDataReference;
  DWORD 			 cCertReference;
  DWORD 			*rgdwCertReference;
  DWORD 			 cAttribute;
  PCRYPT_ATTRIBUTE		 rgAttribute;
} CMC_ADD_ATTRIBUTES_INFO, *PCMC_ADD_ATTRIBUTES_INFO;

typedef struct _CMC_ADD_EXTENSIONS_INFO
{ DWORD 			 dwCmcDataReference;
  DWORD 			 cCertReference;
  DWORD 			*rgdwCertReference;
  DWORD 			 cExtension;
  PCERT_EXTENSION		 rgExtension;
} CMC_ADD_EXTENSIONS_INFO, *PCMC_ADD_EXTENSIONS_INFO;

#endif /* WINVER >= _WIN32_WINNT_WINXP */

#if WINVER >= _WIN32_WINDOWS_98
#ifdef MINGW_TENTATIVE_ASSUMPTIONS
/* FIXME: CERT_ALT_NAME_ENTRY needs definitions for PCERT_OTHER_NAME and
 * (allegedly) CERT_DATA_BLOB (for the the x400Address field, which according to
 * https://msdn.microsoft.com/en-us/library/windows/desktop/aa377173%28v=vs.85%29.aspx
 * is NOT a member of this structure; similarly, neither is pEdiPartyName)
 *
 * The CERT_OTHER_NAME structure, (to which a PCERT_OTHER_NAME would point), is
 * not documented on MSDN, (or on any other Microsoft reference site).  There is,
 * however, a tenuous suggestion within the CERT_ALT_NAME_ENTRY documentation, (at
 * the aforementioned URL), that it comprises an object identifier (OID), and a
 * BLOB specifying the name, (closely resembling a CRYPT_ATTRIBUTE_TYPE_VALUE);
 * that this tenuous resemblance may suffice as an actual representation of a
 * CERT_OTHER_NAME structure is further hinted at, in the form of a SEE ALSO
 * reference to CRYPT_ATTRIBUTE_TYPE_VALUE, which appears to have no other
 * relevance in the CERT_ALT_NAME_ENTRY context; hence, we may infer...
 */
typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE   CERT_OTHER_NAME;
typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE  *PCERT_OTHER_NAME;

typedef struct _CERT_ALT_NAME_ENTRY
{ DWORD 			 dwAltNameChoice;
  union
  { PCERT_OTHER_NAME		 pOtherName;
    LPWSTR			 pwszRfc822Name;
    LPWSTR			 pwszDNSName;
    /* CERT_DATA_BLOB		 x400Address;	*/ /* never implemented? */
    CERT_NAME_BLOB		 DirectoryName;
    /* LPWSTR			 pEdiPartyName;	*/ /* never implemented? */
    LPWSTR			 pwszURL;
    CRYPT_DATA_BLOB		 IPAddress;
    LPSTR			 pszRegisteredID;
  };
} CERT_ALT_NAME_ENTRY, *PCERT_ALT_NAME_ENTRY;

typedef struct _CERT_ALT_NAME_INFO
/* FIXME: this needs CERT_ALT_NAME_ENTRY above, which lacks prereqs */
{ DWORD 			 cAltEntry;
  PCERT_ALT_NAME_ENTRY		 rgAltEntry;
} CERT_ALT_NAME_INFO, *PCERT_ALT_NAME_INFO;

#endif /* MINGW_TENTATIVE_ASSUMPTIONS */

typedef struct _CERT_NAME_VALUE
{ DWORD 			 dwValueType;
  CERT_RDN_VALUE_BLOB		 Value;
} CERT_NAME_VALUE, *PCERT_NAME_VALUE;

typedef struct _CERT_POLICY_QUALIFIER_INFO
{ LPSTR 			 pszPolicyQualifierId;
  CRYPT_OBJID_BLOB		 Qualifier;
} CERT_POLICY_QUALIFIER_INFO, *PCERT_POLICY_QUALIFIER_INFO;

typedef struct _CERT_POLICY_CONSTRAINTS_INFO
{ BOOL				 fRequireExplicitPolicy;
  DWORD 			 dwRequireExplicitPolicySkipCerts;
  BOOL				 fInhibitPolicyMapping;
  DWORD 			 dwInhibitPolicyMappingSkipCerts;
} CERT_POLICY_CONSTRAINTS_INFO, *PCERT_POLICY_CONSTRAINTS_INFO;

#endif /* WINVER >= _WIN32_WINDOWS_98 */

#if WINVER >= _WIN32_WINNT_WINXP
/* Available only on Windows-XP, Windows Server 2003, and later.
 */
typedef struct _CERT_POLICY_MAPPING
{ LPSTR 			 pszIssuerDomainPolicy;
  LPSTR 			 pszSubjectDomainPolicy;
} CERT_POLICY_MAPPING, *PCERT_POLICY_MAPPING;

typedef struct _CERT_POLICY_MAPPINGS_INFO
{ DWORD 			 cPolicyMapping;
  PCERT_POLICY_MAPPING		 rgPolicyMapping;
} CERT_POLICY_MAPPINGS_INFO, *PCERT_POLICY_MAPPINGS_INFO;

#endif /* WINVER >= _WIN32_WINNT_WINXP */

/* Some Crypto Key Provider Information structures.
 */
typedef struct _CRYPT_KEY_PROV_PARAM
{ /* From http://msdn.microsoft.com/en-us/library/aa922935.aspx
   */
  DWORD 			 dwParam;
  BYTE				*pbData;
  DWORD 			 cbData;
  DWORD 			 dwFlags;
} CRYPT_KEY_PROV_PARAM, *PCRYPT_KEY_PROV_PARAM;

typedef struct _CRYPT_KEY_PROV_INFO
{ /* From http://msdn.microsoft.com/en-us/library/aa381420(VS.85).aspx
   */
  LPWSTR			 pwszContainerName;
  LPWSTR			 pwszProvName;
  DWORD 			 dwProvType;
  DWORD 			 dwFlags;
  DWORD 			 cProvParam;
  PCRYPT_KEY_PROV_PARAM 	 rgProvParam;
  DWORD 			 dwKeySpec;
} CRYPT_KEY_PROV_INFO, *PCRYPT_KEY_PROV_INFO;

#define CERT_SET_KEY_PROV_HANDLE_PROP_ID	0x00000001
#define CERT_SET_KEY_CONTEXT_PROP_ID		0x00000001

#define CRYPT_KEYID_DELETE_FLAG 		0x00000010
#define CRYPT_KEYID_SET_NEW_FLAG		0x00002000

/* Certificate crl ctl IDs.
 */
#define CERT_KEY_PROV_HANDLE_PROP_ID			 1
#define CERT_KEY_PROV_INFO_PROP_ID			 2
#define CERT_SHA1_HASH_PROP_ID				 3
#define CERT_MD5_HASH_PROP_ID				 4
#define CERT_HASH_PROP_ID		     CERT_SHA1_HASH_PROP_ID
#define CERT_KEY_CONTEXT_PROP_ID			 5
#define CERT_KEY_SPEC_PROP_ID				 6
#define CERT_IE30_RESERVED_PROP_ID			 7
#define CERT_PUBKEY_HASH_RESERVED_PROP_ID		 8
#define CERT_ENHKEY_USAGE_PROP_ID			 9
#define CERT_CTL_USAGE_PROP_ID		     CERT_ENHKEY_USAGE_PROP_ID
#define CERT_NEXT_UPDATE_LOCATION_PROP_ID		10
#define CERT_FRIENDLY_NAME_PROP_ID			11
#define CERT_PVK_FILE_PROP_ID				12
#define CERT_DESCRIPTION_PROP_ID			13
#define CERT_ACCESS_STATE_PROP_ID			14
#define CERT_SIGNATURE_HASH_PROP_ID			15
#define CERT_SMART_CARD_DATA_PROP_ID			16
#define CERT_EFS_PROP_ID				17
#define CERT_FORTEZZA_DATA_PROP_ID			18
#define CERT_ARCHIVED_PROP_ID				19
#define CERT_KEY_IDENTIFIER_PROP_ID			20
#define CERT_AUTO_ENROLL_PROP_ID			21
#define CERT_PUBKEY_ALG_PARA_PROP_ID			22
#define CERT_CROSS_CERT_DIST_POINTS_PROP_ID		23
#define CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID 	24
#define CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID	25
#define CERT_ENROLLMENT_PROP_ID 			26
#define CERT_DATE_STAMP_PROP_ID 			27
#define CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID	28
#define CERT_SUBJECT_NAME_MD5_HASH_PROP_ID		29
#define CERT_EXTENDED_ERROR_INFO_PROP_ID		30

/* Certificate name type.
 */
#define CERT_NAME_EMAIL_TYPE				 1
#define CERT_NAME_RDN_TYPE				 2
#define CERT_NAME_ATTR_TYPE				 3
#define CERT_NAME_SIMPLE_DISPLAY_TYPE			 4
#define CERT_NAME_FRIENDLY_DISPLAY_TYPE 		 5
#define CERT_NAME_DNS_TYPE				 6
#define CERT_NAME_URL_TYPE				 7
#define CERT_NAME_UPN_TYPE				 8

/* Certificate/CRL, encoded, context or element disposition values.
 */
#define CERT_STORE_ADD_NEW				 1
#define CERT_STORE_ADD_USE_EXISTING			 2
#define CERT_STORE_ADD_REPLACE_EXISTING 		 3
#define CERT_STORE_ADD_ALWAYS				 4

#define CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES	5

#define CERT_STORE_ADD_NEWER				 6
#define CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES 	 7

#define CRYPT_ACQUIRE_CACHE_FLAG		0x00000001
#define CRYPT_ACQUIRE_USE_PROV_INFO_FLAG	0x00000002
#define CRYPT_ACQUIRE_COMPARE_KEY_FLAG		0x00000004
#define CRYPT_ACQUIRE_SILENT_FLAG		0x00000040

#define RSA1024BIT_KEY				0x04000000

/* dwFlags definitions for CryptDeriveKey
 */
#define CRYPT_SERVER				0x00000400

#define KEY_LENGTH_MASK 			0xFFFF0000

/* dwFlag definitions for CryptExportKey
 */
#define CRYPT_Y_ONLY				0x00000001
#define CRYPT_SSL2_FALLBACK			0x00000002
#define CRYPT_DESTROYKEY			0x00000004

/* Used with RSA encryptions/decryptions, CryptExportKey, CryptImportKey,
 * CryptEncrypt, and CryptDecrypt
 */
#define CRYPT_OAEP				0x00000040

#define CRYPT_BLOB_VER3 			0x00000080  /* export version 3 of a blob type */
#define CRYPT_IPSEC_HMAC_KEY			0x00000100  /* CryptImportKey only */

/* dwFlags definitions for CryptDecrypt; see also CRYPT_OAEP, above.
 * Note, the following flag is not supported for CryptEncrypt
 */
#define CRYPT_DECRYPT_RSA_NO_PADDING_CHECK	0x00000020

/* dwFlags definitions for CryptCreateHash
 */
#define CRYPT_SECRETDIGEST			0x00000001

/* dwFlags definitions for CryptHashData
 */
#define CRYPT_OWF_REPL_LM_HASH			0x00000001  /* this is only for the OWF replacement CSP */

/* dwFlags definitions for CryptHashSessionKey
 */
#define CRYPT_LITTLE_ENDIAN			0x00000001

/* dwFlags definitions for CryptSignHash and CryptVerifySignature
 */
#define CRYPT_NOHASHOID 			0x00000001
#define CRYPT_TYPE2_FORMAT			0x00000002
#define CRYPT_X931_FORMAT			0x00000004

/* dwFlag definitions for CryptSetProviderEx and CryptGetDefaultProvider
 */
#define CRYPT_MACHINE_DEFAULT			0x00000001
#define CRYPT_USER_DEFAULT			0x00000002
#define CRYPT_DELETE_DEFAULT			0x00000004

/* algorithm.
 */
#define CALG_SSL3_SHAMD5        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SSL3SHAMD5)

/* End of crypto key provider information structures.
 */

BOOL WINAPI CertCloseStore( HCERTSTORE, DWORD );
BOOL WINAPI CertGetCertificateChain( HCERTCHAINENGINE, PCCERT_CONTEXT, LPFILETIME, HCERTSTORE, PCERT_CHAIN_PARA, DWORD, LPVOID, PCCERT_CHAIN_CONTEXT * );
BOOL WINAPI CertVerifyCertificateChainPolicy( LPCSTR, PCCERT_CHAIN_CONTEXT, PCERT_CHAIN_POLICY_PARA, PCERT_CHAIN_POLICY_STATUS );
void WINAPI CertFreeCertificateChain( PCCERT_CHAIN_CONTEXT );

#define CertNameToStr  __AW_SUFFIXED__( CertNameToStr )
DWORD WINAPI CertNameToStrA( DWORD, PCERT_NAME_BLOB, DWORD, LPSTR, DWORD );
DWORD WINAPI CertNameToStrW( DWORD, PCERT_NAME_BLOB, DWORD, LPWSTR, DWORD );

#define CertOpenSystemStore  __AW_SUFFIXED__( CertOpenSystemStore )
HCERTSTORE WINAPI CertOpenSystemStoreA( HCRYPTPROV, LPCSTR );
HCERTSTORE WINAPI CertOpenSystemStoreW( HCRYPTPROV, LPCWSTR );

HCERTSTORE WINAPI CertOpenStore( LPCSTR, DWORD, HCRYPTPROV, DWORD, const void * );
PCCERT_CONTEXT WINAPI CertFindCertificateInStore( HCERTSTORE, DWORD, DWORD, DWORD, const void *, PCCERT_CONTEXT );
BOOL WINAPI CertFreeCertificateContext( PCCERT_CONTEXT );
PCCERT_CONTEXT WINAPI CertGetIssuerCertificateFromStore( HCERTSTORE, PCCERT_CONTEXT, PCCERT_CONTEXT, DWORD * );
PCCERT_CHAIN_CONTEXT WINAPI CertFindChainInStore( HCERTSTORE, DWORD, DWORD, DWORD, const void *, PCCERT_CHAIN_CONTEXT );

HCERTSTORE WINAPI CertDuplicateStore( HCERTSTORE );
PCCERT_CONTEXT WINAPI CertEnumCertificatesInStore( HCERTSTORE, PCCERT_CONTEXT );
PCCERT_CONTEXT WINAPI CertDuplicateCertificateContext( PCCERT_CONTEXT );

#define CertGetNameString  __AW_SUFFIXED__( CertGetNameString )
DWORD WINAPI CertGetNameStringA( PCCERT_CONTEXT, DWORD, DWORD, void *, LPSTR, DWORD );
DWORD WINAPI CertGetNameStringW( PCCERT_CONTEXT, DWORD, DWORD, void *, LPWSTR, DWORD );

BOOL WINAPI PFXIsPFXBlob( CRYPT_DATA_BLOB * );
PCERT_EXTENSION WINAPI CertFindExtension( LPCSTR, DWORD, CERT_EXTENSION * );
BOOL WINAPI CryptDecodeObject( DWORD, LPCSTR, const BYTE *, DWORD, DWORD, void *, DWORD * );
BOOL WINAPI CryptDecodeObjectEx( DWORD, LPCSTR, const BYTE *, DWORD, DWORD, PCRYPT_DECODE_PARA, void *, DWORD * );
BOOL WINAPI CryptEncodeObject( DWORD, LPCSTR, const void *, BYTE *, DWORD * );
BOOL WINAPI CryptEncodeObjectEx( DWORD, LPCSTR, const void *, DWORD, PCRYPT_ENCODE_PARA, void *, DWORD * );
BOOL WINAPI CertAddCertificateContextToStore( HCERTSTORE, PCCERT_CONTEXT, DWORD, PCCERT_CONTEXT * );
BOOL WINAPI CertCompareCertificate( DWORD, PCERT_INFO, PCERT_INFO );
BOOL WINAPI PFXVerifyPassword( CRYPT_DATA_BLOB *, LPCWSTR, DWORD );
HCERTSTORE WINAPI PFXImportCertStore( CRYPT_DATA_BLOB *, LPCWSTR, DWORD );
BOOL WINAPI CertDeleteCertificateFromStore( PCCERT_CONTEXT );

#define CryptAcquireContext  __AW_SUFFIXED__( CryptAcquireContext )
WINADVAPI BOOL WINAPI CryptAcquireContextA( HCRYPTPROV *, LPCSTR, LPCSTR, DWORD, DWORD );
WINADVAPI BOOL WINAPI CryptAcquireContextW( HCRYPTPROV *, LPCWSTR, LPCWSTR, DWORD, DWORD );

WINADVAPI BOOL WINAPI CryptContextAddRef( HCRYPTPROV, DWORD *, DWORD );
WINADVAPI BOOL WINAPI CryptReleaseContext( HCRYPTPROV, DWORD );
WINADVAPI BOOL WINAPI CryptGenKey( HCRYPTPROV, ALG_ID, DWORD, HCRYPTKEY * );
WINADVAPI BOOL WINAPI CryptDeriveKey( HCRYPTPROV, ALG_ID, HCRYPTHASH, DWORD, HCRYPTKEY * );
WINADVAPI BOOL WINAPI CryptDestroyKey( HCRYPTKEY );

#if WINVER >= _WIN32_WINNT_WIN2K
WINADVAPI BOOL WINAPI CryptDuplicateHash( HCRYPTHASH, DWORD *, DWORD, HCRYPTHASH * );
WINADVAPI BOOL WINAPI CryptDuplicateKey( HCRYPTKEY, DWORD *, DWORD, HCRYPTKEY * );
#endif

WINADVAPI BOOL WINAPI CryptSetKeyParam( HCRYPTKEY, DWORD, PBYTE, DWORD );
WINADVAPI BOOL WINAPI CryptGetKeyParam( HCRYPTKEY, DWORD, PBYTE, PDWORD, DWORD );
WINADVAPI BOOL WINAPI CryptSetHashParam( HCRYPTHASH, DWORD, PBYTE, DWORD );
WINADVAPI BOOL WINAPI CryptGetHashParam( HCRYPTHASH, DWORD, PBYTE, PDWORD, DWORD );
WINADVAPI BOOL WINAPI CryptSetProvParam( HCRYPTPROV, DWORD, PBYTE, DWORD );
WINADVAPI BOOL WINAPI CryptGetProvParam( HCRYPTPROV, DWORD, PBYTE, PDWORD, DWORD );
WINADVAPI BOOL WINAPI CryptGenRandom( HCRYPTPROV, DWORD, PBYTE );
WINADVAPI BOOL WINAPI CryptGetUserKey( HCRYPTPROV, DWORD, HCRYPTKEY * );
WINADVAPI BOOL WINAPI CryptExportKey( HCRYPTKEY, HCRYPTKEY, DWORD, DWORD, PBYTE, PDWORD );
WINADVAPI BOOL WINAPI CryptImportKey( HCRYPTPROV, PBYTE, DWORD, HCRYPTKEY, DWORD, HCRYPTKEY * );
WINADVAPI BOOL WINAPI CryptEncrypt( HCRYPTKEY, HCRYPTHASH, BOOL, DWORD, PBYTE, PDWORD, DWORD );
WINADVAPI BOOL WINAPI CryptDecrypt( HCRYPTKEY, HCRYPTHASH, BOOL, DWORD, PBYTE, PDWORD );
WINADVAPI BOOL WINAPI CryptCreateHash( HCRYPTPROV, ALG_ID, HCRYPTKEY, DWORD, HCRYPTHASH * );
WINADVAPI BOOL WINAPI CryptHashData( HCRYPTHASH, PBYTE, DWORD, DWORD );
WINADVAPI BOOL WINAPI CryptHashSessionKey( HCRYPTHASH, HCRYPTKEY, DWORD );
WINADVAPI BOOL WINAPI CryptGetHashValue( HCRYPTHASH, DWORD, PBYTE, PDWORD );
WINADVAPI BOOL WINAPI CryptDestroyHash( HCRYPTHASH );

#define CryptSignHash  __AW_SUFFIXED__( CryptSignHash )
WINADVAPI BOOL WINAPI CryptSignHashA( HCRYPTHASH, DWORD, LPCSTR, DWORD, PBYTE, PDWORD );
WINADVAPI BOOL WINAPI CryptSignHashW( HCRYPTHASH, DWORD, LPCWSTR, DWORD, PBYTE, PDWORD );

#define CryptVerifySignature  __AW_SUFFIXED__( CryptVerifySignature )
WINADVAPI BOOL WINAPI CryptVerifySignatureA( HCRYPTHASH, PBYTE, DWORD, HCRYPTKEY, LPCSTR, DWORD );
WINADVAPI BOOL WINAPI CryptVerifySignatureW( HCRYPTHASH, PBYTE, DWORD, HCRYPTKEY, LPCWSTR, DWORD );

#define CryptSetProvider  __AW_SUFFIXED__( CryptSetProvider )
WINADVAPI BOOL WINAPI CryptSetProviderA( LPCSTR, DWORD );
WINADVAPI BOOL WINAPI CryptSetProviderW( LPCWSTR, DWORD );

#define CryptEnumProviders  __AW_SUFFIXED__( CryptEnumProviders )
WINADVAPI BOOL WINAPI CryptEnumProvidersA( DWORD, DWORD *, DWORD, DWORD *, LPSTR, DWORD * );
WINADVAPI BOOL WINAPI CryptEnumProvidersW( DWORD, DWORD *, DWORD, DWORD *, LPWSTR, DWORD * );

typedef struct _CRYPTPROTECT_PROMPTSTRUCT
{ /* From http://msdn2.microsoft.com/en-us/library/Aa380263.aspx:
   */
  DWORD cbSize;
  DWORD dwPromptFlags;
  HWND hwndApp;
  LPCWSTR szPrompt;
} CRYPTPROTECT_PROMPTSTRUCT, *PCRYPTPROTECT_PROMPTSTRUCT;


/* From http://msdn2.microsoft.com/en-us/library/aa380261.aspx
 */
BOOL WINAPI CryptProtectData( DATA_BLOB *, LPCWSTR, DATA_BLOB *, PVOID, CRYPTPROTECT_PROMPTSTRUCT *, DWORD, DATA_BLOB * );

/* From http://msdn2.microsoft.com/en-us/library/aa380882.aspx
 */
BOOL WINAPI CryptUnprotectData( DATA_BLOB *, LPWSTR *, DATA_BLOB *, PVOID, CRYPTPROTECT_PROMPTSTRUCT *, DWORD, DATA_BLOB * );

/* From http://msdn2.microsoft.com/en-us/library/aa302402.aspx:
 */
#define CRYPTPROTECT_UI_FORBIDDEN		       0x1
#define CRYPTPROTECT_LOCAL_MACHINE		       0x4

typedef BOOL (WINAPI *PFN_CRYPT_ENUM_KEYID_PROP)( const CRYPT_HASH_BLOB *, DWORD, void *, void *, DWORD, DWORD, void **, DWORD );

BOOL WINAPI CertGetCertificateContextProperty( PCCERT_CONTEXT, DWORD, void *, DWORD * );
BOOL WINAPI CryptEnumKeyIdentifierProperties( const CRYPT_HASH_BLOB *, DWORD, DWORD, LPCWSTR, void *, void *, PFN_CRYPT_ENUM_KEYID_PROP );
BOOL WINAPI CryptAcquireCertificatePrivateKey( PCCERT_CONTEXT, DWORD, void *, HCRYPTPROV *, DWORD *, BOOL * );
PCCERT_CONTEXT WINAPI CertCreateCertificateContext( DWORD, const BYTE *, DWORD );
BOOL WINAPI CryptGetKeyIdentifierProperty( const CRYPT_HASH_BLOB *, DWORD, DWORD, LPCWSTR, void *, void *, DWORD * );
BOOL WINAPI CertSetCertificateContextProperty( PCCERT_CONTEXT, DWORD, DWORD, void * );
BOOL WINAPI CertCompareCertificateName( DWORD, PCERT_NAME_BLOB, PCERT_NAME_BLOB );
BOOL WINAPI CryptSetKeyIdentifierProperty( const CRYPT_HASH_BLOB *, DWORD, DWORD, LPCWSTR, void *, void * );
DWORD WINAPI CertOIDToAlgId( LPCSTR );

#define CryptGetDefaultProvider __AW_SUFFIXED__( CryptGetDefaultProvider )
BOOL WINAPI CryptGetDefaultProviderA( DWORD, DWORD, DWORD, LPSTR, DWORD );
BOOL WINAPI CryptGetDefaultProviderW( DWORD, DWORD, DWORD, LPWSTR, DWORD );

_END_C_DECLS

#endif /* ! _WINCRYPT_H: $RCSfile: wincrypt.h,v $: end of file */
