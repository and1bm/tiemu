#
# Cygnus enhanced version of the iwidget Pane class
# ----------------------------------------------------------------------
# Implements a pane for a paned window widget.  The pane is itself a 
# frame with a child site for other widgets.  The pane class performs
# basic option management.
#
# ----------------------------------------------------------------------
#  AUTHOR: Mark L. Ulferts              EMAIL: mulferts@austin.dsccc.com
#
#  @(#) $Id: pane.tcl,v 1.2 1999/01/28 01:18:26 jingham Exp $
# ----------------------------------------------------------------------
#            Copyright (c) 1995 DSC Technologies Corporation
# ======================================================================
# Permission to use, copy, modify, distribute and license this software 
# and its documentation for any purpose, and without fee or written 
# agreement with DSC, is hereby granted, provided that the above copyright 
# notice appears in all copies and that both the copyright notice and 
# warranty disclaimer below appear in supporting documentation, and that 
# the names of DSC Technologies Corporation or DSC Communications 
# Corporation not be used in advertising or publicity pertaining to the 
# software without specific, written prior permission.
# 
# DSC DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING 
# ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, AND NON-
# INFRINGEMENT. THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, AND THE
# AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE MAINTENANCE, 
# SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS. IN NO EVENT SHALL 
# DSC BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR 
# ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
# WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTUOUS ACTION,
# ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS 
# SOFTWARE.
# ======================================================================

#
# Usual options.
#
itk::usual Pane {
  keep -background -cursor
}

# ------------------------------------------------------------------
#                               PANE
# ------------------------------------------------------------------
itcl::class cyg::Pane {
  inherit itk::Widget
  
  constructor {args} {}
  
  itk_option define -maximum maximum Maximum 0
  itk_option define -minimum minimum Minimum 10
  itk_option define -margin margin Margin 0
  itk_option define -resizable resizable Resizable 1
  
  public method childSite {} {}
}

#
# Provide a lowercased access method for the Pane class.
# 
proc ::cyg::pane {pathName args} {
  uplevel ::cyg::Pane $pathName $args
}

# ------------------------------------------------------------------
#                        CONSTRUCTOR
# ------------------------------------------------------------------
itcl::body cyg::Pane::constructor {args} {
  # 
  # Create the pane childsite.
  #
  itk_component add childsite {
    frame $itk_interior.childsite 
  } {
    keep -background -cursor
  }
  pack $itk_component(childsite) -fill both -expand yes
  
  #
  # Set the itk_interior variable to be the childsite for derived 
  # classes.
  #
  set itk_interior $itk_component(childsite)
  
  eval itk_initialize $args
}

# ------------------------------------------------------------------
#                             OPTIONS
# ------------------------------------------------------------------

# ------------------------------------------------------------------
# OPTION: -minimum
#
# Specifies the minimum size that the pane may reach.
# ------------------------------------------------------------------
itcl::configbody cyg::Pane::minimum {
  set pixels [winfo pixels $itk_component(hull) $itk_option(-minimum)]
  set $itk_option(-minimum) $pixels
}

# ------------------------------------------------------------------
# OPTION: -maximum
#
# Specifies the maximum size that the pane may reach.
# ------------------------------------------------------------------
itcl::configbody cyg::Pane::maximum {
  set pixels [winfo pixels $itk_component(hull) $itk_option(-maximum)]
  set $itk_option(-maximum) $pixels
}

# ------------------------------------------------------------------
# OPTION: -margin
#
# Specifies the border distance between the pane and pane contents.
# This is done by setting the borderwidth of the pane to the margin.
# ------------------------------------------------------------------
itcl::configbody cyg::Pane::margin {
  set pixels [winfo pixels $itk_component(hull) $itk_option(-margin)]
  set itk_option(-margin) $pixels
  $itk_component(childsite) configure -borderwidth $itk_option(-margin)
}

# ------------------------------------------------------------------
#                            METHODS
# ------------------------------------------------------------------

# ------------------------------------------------------------------
# METHOD: childSite
#
# Return the pane child site path name.
# ------------------------------------------------------------------
itcl::body cyg::Pane::childSite {} {
  return $itk_component(childsite)
}
