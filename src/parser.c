/* A recursive-descent parser generated by peg 0.1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 15

  #include "lib.h"
  #define YYSTYPE char *
  #define DUP yy = strdup(yytext)
  #define LPAREN '{'
  #define RPAREN '}'
  #define pc putchar
  #define p printf

#ifndef YY_VARIABLE
#define YY_VARIABLE(T)	static T
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yybegin= yypos, 1)
#endif
#ifndef YY_END
#define YY_END		( yyend= yypos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif

#ifndef YY_PART

typedef void (*yyaction)(char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

YY_VARIABLE(char *   ) yybuf= 0;
YY_VARIABLE(int	     ) yybuflen= 0;
YY_VARIABLE(int	     ) yypos= 0;
YY_VARIABLE(int	     ) yylimit= 0;
YY_VARIABLE(char *   ) yytext= 0;
YY_VARIABLE(int	     ) yytextlen= 0;
YY_VARIABLE(int	     ) yybegin= 0;
YY_VARIABLE(int	     ) yyend= 0;
YY_VARIABLE(int	     ) yytextmax= 0;
YY_VARIABLE(yythunk *) yythunks= 0;
YY_VARIABLE(int	     ) yythunkslen= 0;
YY_VARIABLE(int      ) yythunkpos= 0;
YY_VARIABLE(YYSTYPE  ) yy;
YY_VARIABLE(YYSTYPE *) yyval= 0;
YY_VARIABLE(YYSTYPE *) yyvals= 0;
YY_VARIABLE(int      ) yyvalslen= 0;

YY_LOCAL(int) yyrefill(void)
{
  int yyn;
  while (yybuflen - yypos < 512)
    {
      yybuflen *= 2;
      yybuf= realloc(yybuf, yybuflen);
    }
  YY_INPUT((yybuf + yypos), yyn, (yybuflen - yypos));
  if (!yyn) return 0;
  yylimit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(void)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  ++yypos;
  return 1;
}

YY_LOCAL(int) yymatchChar(int c)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  if (yybuf[yypos] == c)
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchChar(%c) @ %s\n", c, yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(%c) @ %s\n", c, yybuf+yypos));
  return 0;
}

YY_LOCAL(int) yymatchString(char *s)
{
  int yysav= yypos;
  while (*s)
    {
      if (yypos >= yylimit && !yyrefill()) return 0;
      if (yybuf[yypos] != *s)
        {
          yypos= yysav;
          return 0;
        }
      ++s;
      ++yypos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(unsigned char *bits)
{
  int c;
  if (yypos >= yylimit && !yyrefill()) return 0;
  c= yybuf[yypos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yybuf+yypos));
  return 0;
}

YY_LOCAL(void) yyDo(yyaction action, int begin, int end)
{
  while (yythunkpos >= yythunkslen)
    {
      yythunkslen *= 2;
      yythunks= realloc(yythunks, sizeof(yythunk) * yythunkslen);
    }
  yythunks[yythunkpos].begin=  begin;
  yythunks[yythunkpos].end=    end;
  yythunks[yythunkpos].action= action;
  ++yythunkpos;
}

YY_LOCAL(int) yyText(int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yytextlen < (yyleng - 1))
	{
	  yytextlen *= 2;
	  yytext= realloc(yytext, yytextlen);
	}
      memcpy(yytext, yybuf + begin, yyleng);
    }
  yytext[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(void)
{
  int pos;
  for (pos= 0;  pos < yythunkpos;  ++pos)
    {
      yythunk *thunk= &yythunks[pos];
      int yyleng= thunk->end ? yyText(thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yytext));
      thunk->action(yytext, yyleng);
    }
  yythunkpos= 0;
}

YY_LOCAL(void) yyCommit()
{
  if ((yylimit -= yypos))
    {
      memmove(yybuf, yybuf + yypos, yylimit);
    }
  yybegin -= yypos;
  yyend -= yypos;
  yypos= yythunkpos= 0;
}

YY_LOCAL(int) yyAccept(int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone();
      yyCommit();
    }
  return 1;
}

YY_LOCAL(void) yyPush(char *text, int count)	{ yyval += count; }
YY_LOCAL(void) yyPop(char *text, int count)	{ yyval -= count; }
YY_LOCAL(void) yySet(char *text, int count)	{ yyval[count]= yy; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yythunkpos0)

YY_RULE(int) yy_s(); /* 15 */
YY_RULE(int) yy_ws(); /* 14 */
YY_RULE(int) yy_EOF(); /* 13 */
YY_RULE(int) yy_uid(); /* 12 */
YY_RULE(int) yy_int(); /* 11 */
YY_RULE(int) yy__(); /* 10 */
YY_RULE(int) yy_id(); /* 9 */
YY_RULE(int) yy_close(); /* 8 */
YY_RULE(int) yy_open(); /* 7 */
YY_RULE(int) yy_nl(); /* 6 */
YY_RULE(int) yy_enum(); /* 5 */
YY_RULE(int) yy_var(); /* 4 */
YY_RULE(int) yy_comment(); /* 3 */
YY_RULE(int) yy_body(); /* 2 */
YY_RULE(int) yy_main(); /* 1 */

YY_ACTION(void) yy_1_id(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_id\n"));
   DUP ;
}
YY_ACTION(void) yy_1_uid(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_uid\n"));
   DUP ;
}
YY_ACTION(void) yy_1_int(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_int\n"));
   DUP ;
}
YY_ACTION(void) yy_2_enum(char *yytext, int yyleng)
{
#define a yyval[-1]
  yyprintf((stderr, "do yy_2_enum\n"));
   p("'%c) + '", RPAREN) ;
#undef a
}
YY_ACTION(void) yy_1_enum(char *yytext, int yyleng)
{
#define a yyval[-1]
  yyprintf((stderr, "do yy_1_enum\n"));
   p("' + %s(o.%s, function(o)%c\n    return '", MOJO_ENUM_FN, a, LPAREN) ;
#undef a
}
YY_ACTION(void) yy_1_var(char *yytext, int yyleng)
{
#define a yyval[-1]
  yyprintf((stderr, "do yy_1_var\n"));
   p("' + (o.%s) + '", a) ;
#undef a
}
YY_ACTION(void) yy_2_body(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_2_body\n"));
   p("%s", yytext) ;
}
YY_ACTION(void) yy_1_body(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_body\n"));
   p("\\n\\\n") ;
}
YY_ACTION(void) yy_2_main(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_2_main\n"));
   pc('\'') ;
}
YY_ACTION(void) yy_1_main(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_main\n"));
   pc('\'') ;
}

YY_RULE(int) yy_s()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "s"));  if (!yymatchClass((unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l1;
  l2:;	
  {  int yypos3= yypos, yythunkpos3= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l3;  goto l2;
  l3:;	  yypos= yypos3; yythunkpos= yythunkpos3;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "s", yybuf+yypos));
  return 1;
  l1:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "s", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_ws()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "ws"));
  {  int yypos5= yypos, yythunkpos5= yythunkpos;  if (!yy_s()) goto l6;  goto l5;
  l6:;	  yypos= yypos5; yythunkpos= yythunkpos5;  if (!yy_nl()) goto l4;
  }
  l5:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "ws", yybuf+yypos));
  return 1;
  l4:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ws", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_EOF()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "EOF"));
  {  int yypos8= yypos, yythunkpos8= yythunkpos;  if (!yymatchDot()) goto l8;  goto l7;
  l8:;	  yypos= yypos8; yythunkpos= yythunkpos8;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "EOF", yybuf+yypos));
  return 1;
  l7:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOF", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_uid()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "uid"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l9;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\000\000\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l9;
  l10:;	
  {  int yypos11= yypos, yythunkpos11= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l11;  goto l10;
  l11:;	  yypos= yypos11; yythunkpos= yythunkpos11;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l9;  yyDo(yy_1_uid, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "uid", yybuf+yypos));
  return 1;
  l9:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "uid", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_int()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "int"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l12;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l12;
  l13:;	
  {  int yypos14= yypos, yythunkpos14= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l14;  goto l13;
  l14:;	  yypos= yypos14; yythunkpos= yythunkpos14;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l12;  yyDo(yy_1_int, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "int", yybuf+yypos));
  return 1;
  l12:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "int", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy__()
{
  yyprintf((stderr, "%s\n", "_"));
  l16:;	
  {  int yypos17= yypos, yythunkpos17= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l17;  goto l16;
  l17:;	  yypos= yypos17; yythunkpos= yythunkpos17;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yybuf+yypos));
  return 1;
}
YY_RULE(int) yy_id()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "id"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l18;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l18;
  l19:;	
  {  int yypos20= yypos, yythunkpos20= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l20;  goto l19;
  l20:;	  yypos= yypos20; yythunkpos= yythunkpos20;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l18;  yyDo(yy_1_id, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "id", yybuf+yypos));
  return 1;
  l18:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "id", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_close()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "close"));  if (!yy__()) goto l21;  if (!yymatchChar('}')) goto l21;
  l22:;	
  {  int yypos23= yypos, yythunkpos23= yythunkpos;  if (!yymatchChar('}')) goto l23;  goto l22;
  l23:;	  yypos= yypos23; yythunkpos= yythunkpos23;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "close", yybuf+yypos));
  return 1;
  l21:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "close", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_open()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "open"));  if (!yymatchChar('{')) goto l24;
  l25:;	
  {  int yypos26= yypos, yythunkpos26= yythunkpos;  if (!yymatchChar('{')) goto l26;  goto l25;
  l26:;	  yypos= yypos26; yythunkpos= yythunkpos26;
  }  if (!yy__()) goto l24;
  yyprintf((stderr, "  ok   %s @ %s\n", "open", yybuf+yypos));
  return 1;
  l24:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "open", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_nl()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "nl"));
  {  int yypos28= yypos, yythunkpos28= yythunkpos;  if (!yymatchChar('\r')) goto l29;  goto l28;
  l29:;	  yypos= yypos28; yythunkpos= yythunkpos28;  if (!yymatchString("\r\n")) goto l30;  goto l28;
  l30:;	  yypos= yypos28; yythunkpos= yythunkpos28;  if (!yymatchChar('\n')) goto l27;
  }
  l28:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "nl", yybuf+yypos));
  return 1;
  l27:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "nl", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_enum()
{  int yypos0= yypos, yythunkpos0= yythunkpos;  yyDo(yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "enum"));
  {  int yypos32= yypos, yythunkpos32= yythunkpos;  if (!yy_open()) goto l33;  if (!yymatchChar('#')) goto l33;  if (!yy__()) goto l33;  if (!yy_id()) goto l33;  yyDo(yySet, -1, 0);  if (!yy_close()) goto l33;  yyDo(yy_1_enum, yybegin, yyend);  goto l32;
  l33:;	  yypos= yypos32; yythunkpos= yythunkpos32;  if (!yy_open()) goto l31;  if (!yymatchChar('/')) goto l31;  if (!yy__()) goto l31;  if (!yy_id()) goto l31;  yyDo(yySet, -1, 0);  if (!yy_close()) goto l31;  yyDo(yy_2_enum, yybegin, yyend);
  }
  l32:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "enum", yybuf+yypos));  yyDo(yyPop, 1, 0);
  return 1;
  l31:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "enum", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_var()
{  int yypos0= yypos, yythunkpos0= yythunkpos;  yyDo(yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "var"));  if (!yy_open()) goto l34;  if (!yy_id()) goto l34;  yyDo(yySet, -1, 0);  if (!yy_close()) goto l34;  yyDo(yy_1_var, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "var", yybuf+yypos));  yyDo(yyPop, 1, 0);
  return 1;
  l34:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "var", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_comment()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "comment"));  if (!yy_open()) goto l35;  if (!yymatchChar('!')) goto l35;  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l35;
  l36:;	
  {  int yypos37= yypos, yythunkpos37= yythunkpos;
  {  int yypos38= yypos, yythunkpos38= yythunkpos;  if (!yy_close()) goto l38;  goto l37;
  l38:;	  yypos= yypos38; yythunkpos= yythunkpos38;
  }  if (!yymatchDot()) goto l37;  goto l36;
  l37:;	  yypos= yypos37; yythunkpos= yythunkpos37;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l35;  if (!yy_close()) goto l35;
  yyprintf((stderr, "  ok   %s @ %s\n", "comment", yybuf+yypos));
  return 1;
  l35:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "comment", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_body()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "body"));
  {  int yypos40= yypos, yythunkpos40= yythunkpos;  if (!yy_comment()) goto l41;  goto l40;
  l41:;	  yypos= yypos40; yythunkpos= yythunkpos40;  if (!yy_var()) goto l42;  goto l40;
  l42:;	  yypos= yypos40; yythunkpos= yythunkpos40;  if (!yy_enum()) goto l43;  goto l40;
  l43:;	  yypos= yypos40; yythunkpos= yythunkpos40;  if (!yy_nl()) goto l44;  yyDo(yy_1_body, yybegin, yyend);  goto l40;
  l44:;	  yypos= yypos40; yythunkpos= yythunkpos40;  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l39;  if (!yymatchDot()) goto l39;  yyText(yybegin, yyend);  if (!(YY_END)) goto l39;  yyDo(yy_2_body, yybegin, yyend);
  }
  l40:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "body", yybuf+yypos));
  return 1;
  l39:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "body", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_main()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "main"));  yyDo(yy_1_main, yybegin, yyend);  if (!yy_body()) goto l45;
  l46:;	
  {  int yypos47= yypos, yythunkpos47= yythunkpos;  if (!yy_body()) goto l47;  goto l46;
  l47:;	  yypos= yypos47; yythunkpos= yythunkpos47;
  }  yyDo(yy_2_main, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "main", yybuf+yypos));
  return 1;
  l45:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "main", yybuf+yypos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)();

YY_PARSE(int) YYPARSEFROM(yyrule yystart)
{
  int yyok;
  if (!yybuflen)
    {
      yybuflen= 1024;
      yybuf= malloc(yybuflen);
      yytextlen= 1024;
      yytext= malloc(yytextlen);
      yythunkslen= 32;
      yythunks= malloc(sizeof(yythunk) * yythunkslen);
      yyvalslen= 32;
      yyvals= malloc(sizeof(YYSTYPE) * yyvalslen);
      yybegin= yyend= yypos= yylimit= yythunkpos= 0;
    }
  yybegin= yyend= yypos;
  yythunkpos= 0;
  yyval= yyvals;
  yyok= yystart();
  if (yyok) yyDone();
  yyCommit();
  return yyok;
  (void)yyrefill;
  (void)yymatchDot;
  (void)yymatchChar;
  (void)yymatchString;
  (void)yymatchClass;
  (void)yyDo;
  (void)yyText;
  (void)yyDone;
  (void)yyCommit;
  (void)yyAccept;
  (void)yyPush;
  (void)yyPop;
  (void)yySet;
  (void)yytextmax;
}

YY_PARSE(int) YYPARSE(void)
{
  return YYPARSEFROM(yy_main);
}

#endif


void 
Mojo_parse() {
  while (YYPARSE()); 
}

