APPEXE = roman.exe
LIB = libRomanNumUtil.a
TESTEXE = romanNumlib_test.exe

SRCDIR = src
SRCFILES = $(wildcard ${SRCDIR}/*.c)
TESTDIR = test
TESTFILES = $(wildcard ${TESTDIR}/*.c)

BUILDDIR = build
#LIBDIR = libs

APPSRCS =
LIBSRCS =
TESTSRCS =

CC = gcc
CFLAGS = -g -Wall $(shell pkg-config --cflags check)

LD = gcc
LDFLAGS = $(shell pkg-config --libs check)

AR = ar
ARFLAGS = rcs


.PHONY: all app test clean clobber show

app: $(APPEXE)

all: test app

$(APPEXE): $(SRCFILES:.c=.o) main.o
	$(LD) $^ -o $(APPEXE)

test: $(TESTDIR)/${TESTEXE}
	@echo
	@./$(TESTDIR)/$(TESTEXE)

$(TESTDIR)/${TESTEXE}: $(SRCFILES:.c=.o) $(TESTFILES:.c=.o)
	${LD} $^ ${LDFLAGS} -o $(TESTDIR)/${TESTEXE}

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	${CC} ${CFLAGS} -c $< -o $@ -MMD

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	${CC} ${CFLAGS} -c $< -o $@ -MMD


%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -MMD

show:
@echo "CFlags: " $(CFLAGS)
@echo "Libs: " $(LDFLAGS)

clean:
	rm -f ${TESTDIR}/${TESTEXE}
	rm -f ${APPEXE}

clobber: clean
	rm -f ${TESTDIR}/*.o
	rm -f ${SRCDIR}/*.o
	rm -f ${TESTDIR}/*.d
	rm -f ${SRCDIR}/*.d

-include $(wildcard *.d)
-include $(wildcard ${TESTDIR}/*.d)
-include $(wildcard ${SRCDIR}/*.d)
