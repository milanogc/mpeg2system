#include "Visitor.h"

class PrintVisitor : public Visitor {
	public:
		void printDescriptors(unsigned char *descriptors, unsigned length);
		
		void visit(TSPacket *packet);
		void visit(Descriptor *descriptor);
		void visit(Section *section);
		void visit(PatSection *patSection);
		void visit(PmtSection *pmtSection);
		void visit(SdtSection *sdtSection);
		void visit(NitSection *nitSection);
		void visit(IntSection *intSection);
};
