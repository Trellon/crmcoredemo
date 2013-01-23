
ABOUT DEPLOY
------------

The Deploy module is used to deploy Drupal content to other Drupal sites or
arbritary systems. Two concrete use cases are:

 * using it as a content staging solution
 * usgin it to push content downstream from a main site to several sub sites

The provided workflow for working with deployments is very flexible. You can
have different workflows for deploying different kinds of content on your site.
Those different workflows are defined by different "plans". One plan deploys
content to one or many "endpoints". One endpoint usually represents a site or
an arbritary system.

Content that should be deployed can automatically be filtered by a view or
picked manually by an administrator. The aggregated content can be processed
instantly on one page request or visually by the Batch API with a progress bar.
Content can be deployed to endpoints through services as an REST API, XML-RPC
calls or exposed as a Atom feed that clients can subscribe to. The
authentication methods available are basic HTTP authentication and oAuth.

Deployment of plans can be triggered in many different ways. Either manually by
an end user, by a custom Rules event or through a Drush command.

