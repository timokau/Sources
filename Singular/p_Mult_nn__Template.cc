/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/
/***************************************************************
 *  File:    p_Mult_n__Template.cc
 *  Purpose: template for p_Mult_n
 *  Author:  obachman (Olaf Bachmann)
 *  Created: 8/00
 *  Version: $Id: p_Mult_nn__Template.cc,v 1.1 2000-08-29 14:10:27 obachman Exp $
 *******************************************************************/

/***************************************************************
 *
 *   Returns:  p*n
 *   Destroys: p
 *   Const:    n
 *
 ***************************************************************/
poly p_Mult_nn(poly p, const number n, const ring r)
{
  assume(!p_nIsZero(n,r));
  pTest(p);
  
  poly q = p;
  while (p != NULL)
  {
    number nc = pGetCoeff(p);
    pSetCoeff0(p, p_nMult(n, nc, r));
    p_nDelete(&nc, r);
    pIter(p);
  }
  pTest(q);
  return q;
}


