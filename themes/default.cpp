GrayScale lightgray = GrayScale(23);
GrayScale darkgray  = GrayScale(4);
ColourCombination white_on_gray( &lightgray, &darkgray );


BasicColour repo_dirty_fg = BasicColour(7);
BasicColour repo_clean_fg = BasicColour(0);
Colour256 repo_dirty_bg = Colour256(4,0,1);
Colour256 repo_clean_bg = Colour256(3,4,0);

ColourCombination repo_dirty( &repo_dirty_fg, &repo_dirty_bg );
ColourCombination repo_clean( &repo_clean_fg, &repo_clean_bg );
ColourCombination repo_dirty_separator( &darkgray, &repo_dirty_bg );
ColourCombination repo_clean_separator( &darkgray, &repo_clean_bg );


Colour256 short_cwd_bg = Colour256(0,3,1); // green

ColourCombination short_cwd( &darkgray, &short_cwd_bg );
ColourCombination short_cwd_separator( &short_cwd_bg, &darkgray );

Colour256 jobs_fg = Colour256(2,2,5);

ColourCombination jobs_colours( &jobs_fg, &darkgray );

Colour256 status_fail_fg = Colour256(2,0,0);

ColourCombination status_fail( &status_fail_fg, &darkgray );