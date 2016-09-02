/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "elect.h"


void
elect_prog_1(char *host, float c, float v, float t)
{
	CLIENT *clnt;
	outputstruct  *result_1;
	inputstruct  elect_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ELECT_PROG, ELCT_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	elect_1_arg.c = c;
	elect_1_arg.v = v;
	elect_1_arg.t = t;


	result_1 = elect_1(&elect_1_arg, clnt);
	if (result_1 == (outputstruct *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Enery : %4.2f Charge : %4.2f Current : %4.2f Capasitor Reactans : %4.2f Power : %4.2f \n", result_1->e, result_1->q, result_1->i, result_1->z, result_1->p);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 5) {
		printf ("usage: %s server_host coulomb voltage time\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	elect_prog_1 (host, atof(argv[2]), atof(argv[3]), atof(argv[4]));
	exit (0);
}
