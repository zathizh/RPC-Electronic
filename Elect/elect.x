struct outputstruct{
	float e;
	float q;
	float i;
	float z;
	float p;
};

struct inputstruct{
	float c;
	float v;
	float t;
};

program ELECT_PROG{
	version ELCT_VERS{
		outputstruct ELECT(inputstruct)=1;
	}=1;
} = 0x23451111;
