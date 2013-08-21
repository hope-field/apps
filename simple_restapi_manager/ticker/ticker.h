#ifndef TICKER_H
#define TICKER_H

#ifdef	__cplusplus
extern "C" {
#endif

const char*
get_account_info(const char*, const char*, const char*, const char*);
const char*
show_orders(const char*, const char*, const char*, const char*);
const char*
show_trades(const char*, const char*, const char*, const char*);
const char*
get_position_info(const char*, const char*, const char*, const char*);
const char*
order_insert(const char* instrument, const char* price,const char *director, const char *offset, const char *volume
	, const char* f, const char *b, const char *u, const char *p);
const char*
order_delete(const char *instrument, const char *session, const char *frontid, const char* orderref
	, const char *f, const char *b, const char *u, const char *p);

#ifdef	__cplusplus
}
#endif

#endif // TICKER_H
