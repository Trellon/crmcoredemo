Twitter Bootstrap theme for Drupal

1. Download the Bootstrap library v2 (http://twitter.github.com/bootstrap/), make sure the resulting folder is named "bootstrap." If you are using the Github master branch, you will need to also find a way to compile the LESS and JS files since this module looks for bootstrap.css and bootstrap.js. 
2. Put the bootstrap folder inside the twitter_bootstrap theme folder in [path the themes]/twitter_bootstrap/bootstrap/ or use the Twitter Bootstrap UI (http://drupal.org/project/twitter_bootstrap_ui) module with the Libraries API.
3. Put any plugin files into [path the themes]/twitter_bootstrap/bootstrap/js/
4. Make sure you have Jquery 1.7, which is available through the JQuery Update module (http://drupal.org/project/jquery_update/) 7.x-2.x-dev version. You need to make sure the 1.7 version is selected on the configuration page for it to work.

Author: Sjoerd Arendsen