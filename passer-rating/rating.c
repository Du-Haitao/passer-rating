//
//  rating.c
//  passer-rating
//
//  Created by 海涛 on 16/4/2.
//  Copyright © 2016年 Du-Haitao. All rights reserved.
//

#include "rating.h"

static double pinPassingComp(double component)
{
    if (component < 0.0)
        return 0;
    else if (component > 2.375)
        return 2.375;
    else
        return component;
}

float passer_rating(int comps, int atts, int yds, int tds, int ints)
{
    if (atts == 0) {
        return 0;
    }
    double completionComp = (((double)comps /atts) * 100.0 -30.0) /20.0;
    completionComp = pinPassingComp(completionComp);
    double yardageComp = (((double)yds / atts) - 0.3) / 4.0;
    yardageComp = pinPassingComp(yardageComp);
    double touchdownComp = 20.0 * (double)tds / atts;
    touchdownComp = pinPassingComp(touchdownComp);
    double pickComp = 2.375 - (25.0 * (double)ints / atts);
    pickComp = pinPassingComp(pickComp);
    
    double retval = 100.0 * (completionComp + yardageComp + touchdownComp + pickComp) / 6.0;
    return retval;
}