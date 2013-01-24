<?php
/**
 * @file
 * crm_core_demo_content.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function crm_core_demo_content_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => '1',
  'title' => 'Why use it?',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '6f5d65a8-4385-4fcc-90de-9d04589dfcd8',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359036938',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => '0238bfc1-5c0d-4fdb-956c-b5a5d565a839',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is just a short story about why to use CRM Core 

This distro is all about non-profits. Donations, event registration, petitions, volunteer opportunities. It presents tools for collecting this information, and so much more. Reports. Consolidated contact records. Tools for interacting with contacts.

There is a lot more you can do with CRM Core.

- Budding entrepreneurs looking to start their business quickly.
- Sales portal.
- etc

',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is just a short story about why to use CRM Core </p>
<p>This distro is all about non-profits. Donations, event registration, petitions, volunteer opportunities. It presents tools for collecting this information, and so much more. Reports. Consolidated contact records. Tools for interacting with contacts.</p>
<p>There is a lot more you can do with CRM Core.</p>
<p>- Budding entrepreneurs looking to start their business quickly.<br />
- Sales portal.<br />
- etc</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(
    'und' => array(
      0 => array(
        'fid' => '15',
        'alt' => '',
        'title' => '',
        'width' => '900',
        'height' => '280',
        'uid' => '1',
        'filename' => 'why.jpg',
        'uri' => 'public://why.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => '141576',
        'status' => '1',
        'timestamp' => '1359060811',
        'uuid' => '44cfb332-ee78-4d79-a269-41a85ff4fa1d',
      ),
    ),
  ),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 09:15:38 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'Barry Louis Polisar Benefit Concert',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'db0665e6-8fc4-97a4-116d-829a63223f2a',
  'type' => 'event',
  'language' => 'und',
  'created' => '1356032449',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => '0874c9ee-f10c-9584-4d44-2f7e5944f17a',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'Barry Louis Polisar performs at Maryland Hall for the Creative Arts, 801 Chase St, Annapolis benefitting Chesapeake Children Museum. Performing such ditties as “Giggle, Tickle, Fiddle, and Wiggle Around” and “My Brother Thinks He\'s A Banana”, he\'s called “a one man symphony of comic anarchy” by the Baltimore Sun.

A Parents\' Choice Award winner, he has written songs for Sesame Street and is on the soundtrack of the film Juno. Whether you\'re a child or former child, it would be silly not to come.
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Barry Louis Polisar performs at Maryland Hall for the Creative Arts, 801 Chase St, Annapolis benefitting Chesapeake Children Museum. Performing such ditties as “Giggle, Tickle, Fiddle, and Wiggle Around” and “My Brother Thinks He\'s A Banana”, he\'s called “a one man symphony of comic anarchy” by the Baltimore Sun.</p>
<p>A Parents\' Choice Award winner, he has written songs for Sesame Street and is on the soundtrack of the film Juno. Whether you\'re a child or former child, it would be silly not to come.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_crmer_address' => array(
    'und' => array(
      0 => array(
        'country' => 'US',
        'administrative_area' => 'MD',
        'sub_administrative_area' => NULL,
        'locality' => 'Annapolis',
        'dependent_locality' => NULL,
        'postal_code' => '20012',
        'thoroughfare' => '100 Main Street',
        'premise' => '',
        'sub_premise' => NULL,
        'organisation_name' => NULL,
        'name_line' => NULL,
        'first_name' => NULL,
        'last_name' => NULL,
        'data' => NULL,
      ),
    ),
  ),
  'field_crmer_event_date' => array(
    'und' => array(
      0 => array(
        'value' => '2013-01-13 19:00:00',
        'value2' => '2013-01-13 22:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_crmer_event_phone' => array(
    'und' => array(
      0 => array(
        'number' => '4109901993',
        'country_codes' => 'us',
        'extension' => NULL,
      ),
    ),
  ),
  'field_crmer_redirect_path' => array(),
  'field_crmer_reg_price' => array(
    'und' => array(
      0 => array(
        'amount' => '2000',
        'currency_code' => 'USD',
        'data' => array(
          'components' => array(),
        ),
      ),
    ),
  ),
  'field_crmer_reg_product' => array(
    'und' => array(
      0 => array(
        'product_id' => '1',
      ),
    ),
  ),
  'field_crmer_registration' => array(
    'und' => array(
      0 => array(
        'value' => 'Internal',
      ),
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2012-12-20 14:40:49 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'Animal Shelter Volunteer',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'b7125780-0a57-1b94-5d94-a77b17666373',
  'type' => 'volunteer_opportunity',
  'language' => 'und',
  'created' => '1357019534',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => '150a8b80-48d8-37e4-8903-c4b787da102b',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'Volunteers are needed for daily care of cats and kittens. Duties include: feeding, cleaning litter boxes and cages, changing and washing bedding from cages and overall general cleaning such as sweeping and mopping. Must be able to work well with others and with felines of all ages. Seriuos inquires only! You must be willing to commit one day a week for six consecutive weeks. We house 60-70 cats - if you have allergies or asthma this is not the best place for you.
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Volunteers are needed for daily care of cats and kittens. Duties include: feeding, cleaning litter boxes and cages, changing and washing bedding from cages and overall general cleaning such as sweeping and mopping. Must be able to work well with others and with felines of all ages. Seriuos inquires only! You must be willing to commit one day a week for six consecutive weeks. We house 60-70 cats - if you have allergies or asthma this is not the best place for you.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_crmvo_date' => array(
    'und' => array(
      0 => array(
        'value' => '2013-01-01 05:45:00',
        'value2' => '2013-01-01 05:45:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'UTC',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_crmvo_event' => array(),
  'field_crmvo_location' => array(
    'und' => array(
      0 => array(
        'country' => 'US',
        'administrative_area' => 'WI',
        'sub_administrative_area' => NULL,
        'locality' => 'Milwaukee',
        'dependent_locality' => NULL,
        'postal_code' => 'WI53220',
        'thoroughfare' => '5349 W Forest Home Ave',
        'premise' => '',
        'sub_premise' => NULL,
        'organisation_name' => NULL,
        'name_line' => NULL,
        'first_name' => NULL,
        'last_name' => NULL,
        'data' => NULL,
      ),
    ),
  ),
  'field_crmvo_redirect' => array(),
  'field_crmvo_slots' => array(
    'und' => array(
      0 => array(
        'value' => '10',
      ),
    ),
  ),
  'field_crmvo_time' => array(
    'und' => array(
      0 => array(
        'value' => '120',
      ),
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-01 00:52:14 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'How we built the petitions feature',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '49a7d4eb-f405-441c-8b06-b2f79fd4f7fc',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359037022',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => '59baf944-4cbf-4884-8e1e-0fcd8dddb64e',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'Recipe for a great citizen feedback and online activity tool.

Contents:

- one content type
- one CRM Core Profile
- one activity type
- several views, to create fancy reports
- a little code on the backend for seasoning',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Recipe for a great citizen feedback and online activity tool.</p>
<p>Contents:</p>
<p>- one content type<br />
- one CRM Core Profile<br />
- one activity type<br />
- several views, to create fancy reports<br />
- a little code on the backend for seasoning</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(
    'und' => array(
      0 => array(
        'fid' => '13',
        'alt' => '',
        'title' => '',
        'width' => '900',
        'height' => '280',
        'uid' => '1',
        'filename' => 'hands.jpg',
        'uri' => 'public://hands.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => '193696',
        'status' => '1',
        'timestamp' => '1359059897',
        'uuid' => '17ee2f29-0f7d-44eb-9759-c201599b1820',
      ),
    ),
  ),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 09:17:02 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'How Drupal Commerce fits into things',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'b0c9d0b8-019f-405d-84e7-8aa91b8ae408',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359037068',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => '97fa24ed-7705-48ec-9c52-2f20b1776b54',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'We have 2 different examples of how to integrate CRM Core with Drupal commerce.

Drupal commerce is used to process payments for donations and event registration. 

Event registration uses a traditional cart approach.

Donations is an inline form for processing payments through the site.',
        'summary' => 'We have 2 different examples of how to integrate CRM Core with Drupal commerce.

Drupal commerce is used to process payments for donations and event registration. ',
        'format' => 'filtered_html',
        'safe_value' => '<p>We have 2 different examples of how to integrate CRM Core with Drupal commerce.</p>
<p>Drupal commerce is used to process payments for donations and event registration. </p>
<p>Event registration uses a traditional cart approach.</p>
<p>Donations is an inline form for processing payments through the site.</p>
',
        'safe_summary' => '<p>We have 2 different examples of how to integrate CRM Core with Drupal commerce.</p>
<p>Drupal commerce is used to process payments for donations and event registration.</p>
',
      ),
    ),
  ),
  'field_header_image' => array(
    'und' => array(
      0 => array(
        'fid' => '9',
        'alt' => '',
        'title' => '',
        'width' => '900',
        'height' => '280',
        'uid' => '1',
        'filename' => 'commerce.jpg',
        'uri' => 'public://commerce.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => '279260',
        'status' => '1',
        'timestamp' => '1359052815',
        'uuid' => '4be901d0-5cf7-4911-a3c9-e64af063bf53',
      ),
    ),
  ),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 09:17:48 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'How we built the donations module',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '4e9ba22b-e17e-4e30-b834-7e5f73c87f70',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359032394',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => 'ae3f6095-9335-4a2d-b8d0-6b610978fe61',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This will be a run down of how we built the donations module

- discuss the profile
- discuss the integration with commerce

- discuss the reports 
- talk about the limitations with views
- talk about how they are overridden
- time of day is it\'s own callback',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This will be a run down of how we built the donations module</p>
<p>- discuss the profile<br />
- discuss the integration with commerce</p>
<p>- discuss the reports<br />
- talk about the limitations with views<br />
- talk about how they are overridden<br />
- time of day is it\'s own callback</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(
    'und' => array(
      0 => array(
        'fid' => '14',
        'alt' => '',
        'title' => '',
        'width' => '900',
        'height' => '280',
        'uid' => '1',
        'filename' => 'donations.jpg',
        'uri' => 'public://donations.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => '294026',
        'status' => '1',
        'timestamp' => '1359060200',
        'uuid' => '0df0fff6-6301-4237-bac5-9acfcda9c723',
      ),
    ),
  ),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 07:59:54 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'What will you find in it?',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'ce651c10-820f-4c19-95e2-47f5d344b5d7',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359036964',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => 'b793e54e-5569-4169-ad36-9261067ab63a',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is just a short story about what you will find in CRM Core Demo.

CRM Core does all the basics.
Contacts - stores contact records. Configure them the same way you would a node. Unlimited fields, flexible storage options. Integration with user accounts.
Relationships - store relationships between contacts. Find out who is working for who.
Activities - keep a record of everything someone has done with your site.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is just a short story about what you will find in CRM Core Demo.</p>
<p>CRM Core does all the basics.<br />
Contacts - stores contact records. Configure them the same way you would a node. Unlimited fields, flexible storage options. Integration with user accounts.<br />
Relationships - store relationships between contacts. Find out who is working for who.<br />
Activities - keep a record of everything someone has done with your site.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 09:16:04 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'What is this demo all about?',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'bed8d71c-942d-4ec9-bad9-078725c75e48',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359036914',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => 'ccce9d8c-b701-4946-a548-5d2c1bbea0df',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is just a short story about what CRM Core Demo is all about.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is just a short story about what CRM Core Demo is all about.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 09:15:14 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'How to use CRM Core Profile',
  'log' => '',
  'status' => '1',
  'comment' => '2',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'd35bca28-0917-490d-970c-fb3a7d86c1dd',
  'type' => 'blog_post',
  'language' => 'und',
  'created' => '1359032422',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => 'd370d854-31a2-4c08-bfaa-d62050b5efd3',
  'revision_uid' => '1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This will be a run down of how to use CRM Core Profile',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This will be a run down of how to use CRM Core Profile</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_header_image' => array(
    'und' => array(
      0 => array(
        'fid' => '12',
        'alt' => '',
        'title' => '',
        'width' => '900',
        'height' => '280',
        'uid' => '1',
        'filename' => 'profile.jpg',
        'uri' => 'public://profile_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => '337342',
        'status' => '1',
        'timestamp' => '1359057086',
        'uuid' => 'f26d58fe-3962-43c3-9430-c5c59bd70e85',
      ),
    ),
  ),
  'field_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2013-01-24 08:00:22 -0500',
);
  $nodes[] = array(
  'uid' => '1',
  'title' => 'This is an online petition',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'e41aaa86-e97c-1844-e92e-8558e8e5e236',
  'type' => 'online_petition',
  'language' => 'und',
  'created' => '1356068527',
  'tnid' => '0',
  'translate' => '0',
  'uuid' => 'e73f1a76-c2f9-5454-39c3-fd0ab4e44b93',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is an online petition.

We want you to sign up.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is an online petition.</p>
<p>We want you to sign up.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_crm_petition_duration' => array(
    'und' => array(
      0 => array(
        'value' => '2012-12-21 00:00:00',
        'value2' => '2012-12-21 00:00:00',
        'timezone' => 'America/New_York',
        'timezone_db' => 'America/New_York',
        'date_type' => 'datetime',
      ),
    ),
  ),
  'field_crm_petition_goal' => array(
    'und' => array(
      0 => array(
        'value' => '500',
      ),
    ),
  ),
  'field_crm_petition_image' => array(),
  'field_crm_petition_redirect_path' => array(),
  'field_crm_petition_tags' => array(),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '1',
  'comment_count' => '0',
  'name' => 'admin',
  'picture' => '0',
  'data' => 'b:0;',
  'date' => '2012-12-21 00:42:07 -0500',
);
  return $nodes;
}
